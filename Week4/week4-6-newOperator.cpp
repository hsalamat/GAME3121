//new is an operator in C++ programming language, it is also used to declare memory for N blocks at run time.
//new is an operator whereas malloc() is a library function.
//new allocates memory and calls constructor for object initialization.But malloc() allocates memory and does not call constructor.
//Return type of new is exact data type while malloc() returns void* .
//new is faster than malloc() because an operator is always faster than a function.
//
//Hooman Salamat

#include <iostream>
using namespace std;

int main()
{
	int* p; //pointer declaration
	int i = 0;

	//allocating space for 5 integers
	p = new int[5];

	cout << "Enter elements :\n";
	for (i = 0; i < 5; i++)
		cin >> p[i];

	cout << "Input elements are :\n";
	for (i = 0; i < 5; i++)
		cout << p[i] << endl;

	delete p;
	return 0;
}