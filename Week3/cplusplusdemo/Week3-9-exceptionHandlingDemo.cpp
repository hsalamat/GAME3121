/** @file Week3-9-exceptionHandlingDemo.cpp
 *  @brief Exception Handling Demo
 *
 *  a function that is 40 calls deep in the call stack might detect a problem that can only be handled by the top-level
 *  game loop, or by main(). In this scenario, every one of the 40 functions on
 *  the call stack would need to be written so that it can pass an appropriate error
 *  code all the way back up to the top-level error-handling function.
 *  One way to solve this problem is to throw an exception. Exception handling
 *  is a very powerful feature of C++. It allows the function that detects a
 *  problem to communicate the error to the rest of the code without knowing
 *  anything about which function might handle the error. When an exception is
 *  thrown, relevant information about the error is placed into a data object of the
 *  programmer’s choice known as an exception object. The call stack is then automatically
 *  unwound, in search of a calling function that has wrapped its call
 *  in a try-catch block. If a try-catch block is found, the exception object is
 *  matched against all possible catch clauses, and if a match is found, the corresponding
 *  catch’s code block is executed.
 * 
 *  @attention Ellipsis in C++ allows the function to accept an indeterminate number of arguments. It is also known as the variable argument list. Ellipsis tells the compiler to not check the type and number of parameters the function should accept which allows the user to pass the variable argument list.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
#include <exception>
using namespace std;

class myexception : public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
} myex;

int main() {
	try
	{
		throw 20;
	}
	catch (int e)
	{
		cout << "An exception occurred. Exception # " << e << '\n';
	}


	try {
		throw 'a';
	}
	catch (char excp) {
		cout << "Caught " << excp << endl;
	}


	try {
		throw 10;
	}
	catch (char* excp) {
		cout << "Caught " << excp;
	}
	catch (...) {
		cout << "Default Exception\n";
	}


	try
	{
		throw myex;
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}

	// bad_alloc standard exception
	//The exception that may be caught by the exception handler in this example is a bad_alloc. Because bad_alloc is derived from the standard base class exception, it can be caught (capturing by reference, captures all related classes).
	try
	{
		int* myarray = new int[10000];
	}
	catch (exception& e)
	{
		cout << "Standard exception: " << e.what() << endl;
	}
	return 0;
}

