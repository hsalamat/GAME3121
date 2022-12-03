#pragma once
#include<Windows.h>
#include<iostream>

using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


typedef unsigned int U32;

int VDebugPrintF(const char* format, va_list argList)
{
	const U32 MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];
	//int vsnprintf (char * s, size_t n, const char * format, va_list arg );
	//Write formatted data from variable argument list to sized buffer
	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, argList);
	// Now that we have a formatted string, call the  Win32 API.
	OutputDebugStringA(s_buffer);
	return charsWritten;
}


//Notice that two functions are implemented : DebugPrintF() takes a variable - length argument list(specified via the ellipsis, …), 
//while VDebug - PrintF() takes a va_list argument.This is done so that programmers can
//build additional printing functions in terms of VDebugPrintF(). (It’s impossible to pass ellipses from one function to another, but it is possible to pass va_lists around.)
int DebugPrintF(const char* format, ...)
{
	va_list argList;  //This type is used as a parameter for the macros defined in <cstdarg> to retrieve the additional arguments of a function.
	va_start(argList, format); //Initialize a variable argument list
	int charsWritten = VDebugPrintF(format, argList);
	va_end(argList); //End using variable argument list
	return charsWritten;
}

int g_verbosity = 0;
void VerboseDebugPrintF(int verbosity, const char* format, ...)
{
	// Only print when the global verbosity level is
// high enough.
	if (g_verbosity >= verbosity)
	{
		va_list argList;  //This type is used as a parameter for the macros defined in <cstdarg> to retrieve the additional arguments of a function.
		va_start(argList, format); //Initialize a variable argument list
		VDebugPrintF(format, argList);
		va_end(argList); //End using variable argument list

	}
}


struct AutoProfile
{
	AutoProfile(const char* name)
	{
		m_name = name;
		//The performance timer measures time in units called counts.
		QueryPerformanceCounter(&m_startTime);
		//To get the frequency(counts per second) of the performance timer
		//the number of seconds (or fractions of a second) per count is just the reciprocal of the counts per second : mSecondsPerCount = 1.0 / (double)countsPerSec;
		QueryPerformanceFrequency(&m_frequency);
	}

	~AutoProfile()
	{
		LARGE_INTEGER endTime, DifferenceOfTime;
		QueryPerformanceCounter(&endTime);
		
		//QuadPart represents a 64-bit signed integer (for example: 670644208300)
		//Every LargeInteger is a union of High Part (long:156 ) and Low Part (unsigned long: 629310124)
		
		DifferenceOfTime.QuadPart = endTime.QuadPart - m_startTime.QuadPart;


		DifferenceOfTime.QuadPart *= 1000000; //it's in microseconds

		//To convert a time reading valueInCounts to microseconds, we just divide it by frequency
		DifferenceOfTime.QuadPart /= m_frequency.QuadPart; //For Tick per seconds

		DifferenceOfTime.QuadPart /= 1000; //the value is in milliseconds now

		cout << RED << m_name << " Execution Time in milliseconds is: " << DifferenceOfTime.QuadPart << endl;		
		VerboseDebugPrintF(0, "\nInformation: Execution Time in milliseconds is: %d\n", DifferenceOfTime.QuadPart);

		//g_profileManager.storeSample(m_name, elapsedTime);

		cout << RESET;
	}
	const char* m_name;
	LARGE_INTEGER m_startTime, m_frequency;
};
#define PROFILE(name) AutoProfile p(name)
