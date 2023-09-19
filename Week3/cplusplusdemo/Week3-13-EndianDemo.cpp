/** @file Week3-13-EndianDemo.cpp
 *  @brief Endian Demo
 *
 *  Multibyte integers can be stored into memory in one of two ways :
 *  Little - endian : If a microprocessor stores the least significant byte of a multibyte value at 
 *  a lower memory address than the most significant byte.
 *  Big - endian : stores the most significant byte of a multibyte value at a lower memory address
 *  this microprocessor is little endian becuase 0x34 is stored in the lowest address and 0xAB is in the highest
 * 
 *  Most programmers don’t need to think much about endianness. However,
 *  when you’re a game programmer, endianness can become a bit of a thorn in
 *  your side. This is because games are usually developed on a Windows or Linux
 *  machine running an Intel Pentium processor (which is little-endian), but run
 *  on a console such as the Wii, Xbox or PlayStation —all three of which
 *  utilize a variant of the PowerPC processor (which can be configured to use
 *  either endianness, but is big-endian by default).
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */




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