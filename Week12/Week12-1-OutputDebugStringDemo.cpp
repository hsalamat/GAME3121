/** @file Week12-1-OutputDebugStringDemo
 *  @brief Output Debug String Demo
 *  The Windows SDK function OutputDebugString() is great for printing debugging
 *  information to Visual Studio’s Debug Output window.However,
 *  unlike printf(), OutputDebugString() does not support formatted
 *  output—it can only print raw strings in the form of arrays.For this reason,
 *  most Windows game engines wrap it in a custom function, like this:
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> // for va_list et al
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h> // for OutputDebugString()
typedef unsigned int U32;

int VDebugPrintF(const char* format, va_list argList)
{
	const U32 MAX_CHARS = 1024;
	static char s_buffer[MAX_CHARS];
	//!The vsnprint() function was introduced in C++ 11. Unlike vsprintf(), 
	//! the maximum number of characters that can be written to the buffer is specified in vsnprintf().
	//! int vsnprintf (char * s, size_t n, const char * format, va_list arg );
	int charsWritten = vsnprintf(s_buffer, MAX_CHARS, format, argList);
	// Now that we have a formatted string, call the  Win32 API.
	OutputDebugStringA(s_buffer);
	return charsWritten;
}


//!  DebugPrintF() takes a variable - length argument list(specified via the ellipsis, …), 
//!  This is done so that programmers can build additional printing functions in terms of VDebugPrintF(). 
//!  @note It’s impossible to pass ellipses from one function to another, but it is possible to pass va_lists around.
int DebugPrintF(const char* format, ...)
{
	va_list argList;  //This type is used as a parameter for the macros defined in <cstdarg> to retrieve the additional arguments of a function.
	va_start(argList, format); //Initialize a variable argument list
	int charsWritten = VDebugPrintF(format, argList);
	va_end(argList); //End using variable argument list
	return charsWritten;
}

int main(int argc, char* argv[])
{
	//output debug info in the VS debugger
	int gameLevel = 1, gameSpeed = 60;
	OutputDebugString(L"Testing Formmated OutputDebugString... this will produce output in the Output window of the VS Debugger");
	DebugPrintF("\nGameLevel: %d & GameSpeed: %d\n", gameLevel, gameSpeed);

	//output debug info in the console (for console application)
	char buffer[50];
	int n, a = 5, b = 3;
	n = sprintf(buffer, "%d plus %d is %d", a, b, a + b);
	printf("[%s] is a string %d chars long. This is only good for Console applications and not Win32!\n", buffer, n);
	

	//! output deug info in VS debugger
	char buf[4096];
	char* msgbuf = buf;
	sprintf(buf, "My gameLevel is %d\n", gameLevel);
	OutputDebugStringA(buf);

	return 0;
}