//Multibyte integers can be stored into memory in one of two ways :
//Little - endian : If a microprocessor stores the least significant byte of a multibyte value at a lower memory address than the most significant byte
//Big - endian : stores the most significant byte of a multibyte value at a lower memory address
//this microprocessor is little endian becuase 0x34 is stored in the lowest address and 0xAB is in the highest


#include <iostream>
using namespace std;

typedef unsigned int U32;
typedef unsigned char U8;

void main()
{
	U32 value = 0xCDAB1234;
	U8* pBytes = (U8*)&value;
	char hex_string[4];

	cout << "the original value is: " << std::hex << value << endl;
	sprintf_s(hex_string, "%X", *pBytes); //convert number to hex
	cout << hex_string << endl;
	sprintf_s(hex_string, "%X", *(pBytes + 0x1)); //convert number to hex
	cout << hex_string << endl;
	sprintf_s(hex_string, "%X", *(pBytes + 0x2)); //convert number to hex
	cout << hex_string << endl;
	sprintf_s(hex_string, "%X", *(pBytes + 0x3)); //convert number to hex
	cout << hex_string << endl;

}