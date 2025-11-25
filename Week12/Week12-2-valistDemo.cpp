
/** @file Week12-0-valistDemo
 *  @brief Ellipsis Demo
 *  Ellipsis (three dots) in C++ allows the function to accept an indeterminate number of arguments. 
    It is also known as the variable argument list.
    va_arg takes a va_list and a variable type, and returns the next argument in the list
    in the form of whatever variable type it is told.It then moves down the list
    to the next argument.For example, va_arg(a_list, double) will return the next argument,
    assuming it exists, in the form of a double.The next time it is called,
    it will return the argument following the last returned number, if one exists.
    Note that you need to know the type of each argument--
    that's part of why printf requires a format string!
    Once you're done, use va_end to clean up the list : va_end(a_list);
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


//#include <stdarg.h>
#include <cstdarg>
#include <stdio.h>
#include <iostream>
using namespace std;

//! this function will take the number of values to average followed by all of the numbers to average 
double average(int num, ...)
{
    va_list arguments;
    double sum = 0;

    //! Initializing arguments to store all values after num 
    va_start(arguments, num);

    // Sum all the inputs; we still rely on the function caller to tell us how many there are 
    for (int x = 0; x < num; x++)
    {
        sum += va_arg(arguments, double);
    }
    va_end(arguments);                  // Cleans up the list

    return sum / num;
}

void PrintFError(const char* format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    

    //int vsnprintf (char * s, size_t n, const char * format, va_list arg );
    //Write formatted data from variable argument list to sized buffer
    vsnprintf(buffer, 256, format, args);
    
    //The C library function void perror(const char* str) prints a descriptive error message to stderr.
    perror(buffer);
    va_end(args);
}

//FILE* stream;
int main()
{
    //! this computes the average of 13.2, 22.3 and 4.5 (3 indicates the number of values to average) 
    printf("%f\n", average(3, 12.2, 22.3, 4.5));
    //! here it computes the average of the 5 values 3.3, 2.2, 1.1, 5.5 and 3.3 */
    printf("%f\n", average(5, 3.3, 2.2, 1.1, 5.5, 3.3));

    FILE* pFile;
    char szFileName[] = "myfile.txt";
    char szPathName[] = "root/gameengine/mydirectory/";

    errno_t err;

    // Open for read (will fail if file "myfile.txt" doesn't exist)
    err = fopen_s(&pFile, szFileName, "r");
    if (err == 0)
    {
        PrintFError("The file '%s' was  opened. Path Name: %s",szFileName, szPathName);
    }
    else
    {
        PrintFError("The file '%s' was not opened. Path Name: %s", szFileName, szPathName);
    }

    // Close stream if it isn't NULL
    if (pFile)
    {
        err = fclose(pFile);
        if (err == 0)
        {
            PrintFError("The file '%s' was  closed. ", szFileName);
        }
        else
        {
            PrintFError("The file '%s' was  not closed. ", szFileName);
        }
    }

    // All other files are closed:
    int numclosed = _fcloseall();
    //printf("Number of files closed by _fcloseall: %u\n", numclosed);
    PrintFError("Number of files closed by _fcloseall: %u\n", numclosed);
}