/** @file Week12-2-VerbosityDemo
 *  @brief Verbosity Demo
 *  Once you’ve gone to the trouble of adding a bunch of print statements to your
 *  code in strategically chosen locations, it’s nice to be able to leave them there,
 *  in case they’re needed again later.To permit this, most engines provide some
 *  kind of mechanism for controlling the level of verbosity via the command line,
 *  or dynamically at runtime.When the verbosity level is at its minimum value
 *  (usually zero), only critical error messages are printed.When the verbosity is
 *  higher, more of the print statements embedded in the code start to contribute
 *  to the output.
 *  The WIN32_LEAN_AND_MEAN symbol was introduced  as a way to exclude a bunch of Windows header files when you include windows.h.
 *  You can take a look at your windows.h file to see which ones they are.
 *  VSColoroutput https://marketplace.visualstudio.com/items?itemName=MikeWard-AnnArbor.VSColorOutput64
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
#include <stdio.h> // for va_list et al
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h> // for OutputDebugString()
#include "ConsoleColor.h"
typedef unsigned int U32;
using namespace std;

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
	//! Only print when the global verbosity level is high enough.
	if (g_verbosity >= verbosity)
	{
		va_list argList;  //This type is used as a parameter for the macros defined in <cstdarg> to retrieve the additional arguments of a function.
		va_start(argList, format); //Initialize a variable argument list
		VDebugPrintF(format, argList);
		va_end(argList); //End using variable argument list

	}
}


int main(int argc, char* argv[])
{
	cout << blue << "hi classs" << green << "bye class " << red << "have a nice weekend class" << endl;
	int gameLevel = 1, gameSpeed = 60;
	DebugPrintF("\nVerbosity is set at: %d\n", g_verbosity);
	OutputDebugString(L"Testing Formmated OutputDebugString... this will produce output in the Output window of the VS Debugger");
	VerboseDebugPrintF(0, "\nWarning GameLevel: %d & GameSpeed: %d\n", gameLevel, gameSpeed);

	OutputDebugString(L"\nWarning: this is a warning");
	OutputDebugString(L"\nInformation: this is a Verbosity Demo");
	OutputDebugString(L"\nError: this is an error");

	cout << green << "Verbosity Demo" << white << endl;
	return 0;
}