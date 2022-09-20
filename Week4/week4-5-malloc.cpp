//malloc() is a library function of stdlib.h and it was used in C language to allocate memory for N blocks at run time, 
//it can also be used in C++ programming language.
//Whenever a program needs memory to declare at run time we can use this function.
//Hooman Salamat


#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int* p; //pointer declaration
	int i = 0;

	//allocating space for 5 integers
	p = (int*)malloc(sizeof(int) * 5);

	cout << "Enter elements :\n";
	for (i = 0; i < 5; i++)
		cin >> p[i];

	cout << "Input elements are :\n";
	for (i = 0; i < 5; i++)
		cout << p[i] << endl;

	free(p);
	return 0;
}