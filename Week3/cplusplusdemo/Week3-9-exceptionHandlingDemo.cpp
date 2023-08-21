// using standard exceptions
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
		cout << "An exception occurred. Exception Nr. " << e << '\n';
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

