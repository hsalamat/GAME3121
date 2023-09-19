/** @file Week3-14-IntegerEndianSwappingDemo.cpp
 *  @brief Integer Endian Swapping Demo
 *
 *  Games are usually developed on a Windows or Linux machine running an Intel Pentium processor(which is little - endian), but run on a console such as the Wii, Xbox 360 or PlayStation 3—all three of which
 *  utilize a variant of the PowerPC processor(which can be configured to use either endianness, but is big - endian by default).
 *  Now imagine what happens when you generate a data file for consumption by your game engine on an Intel processorand then try to load that data file into your engine running on a PowerPC processor.
 *  
 *  Endian - swapping an integer is not conceptually difficult.You simply start at
 *  the most significant byte of the value and swap it with the least significant
 *  byte; you continue this process until you reach the halfway point in the value.
 *  For example, 0xA7891023 would become 0x231089A7.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
using namespace std;

typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;

struct Example
{
	U32 m_a;
	U16 m_b;
	U32 m_c;
};

inline U16 swapU16(U16 value)
{
	return ((value & 0x00FF) << 8)  //0xEF67 00FF ==> 0067 ==> 6700 |
		| ((value & 0xFF00) >> 8); // 00EF67 FF00 ==> EF00 ==> 00EF
}
inline U32 swapU32(U32 value)
{
	return ((value & 0x000000FF) << 24)  //0xABCD1234   34000000 |
		| ((value & 0x0000FF00) << 8)	//				00120000 |
		| ((value & 0x00FF0000) >> 8)    //             0000CD00 |
		| ((value & 0xFF000000) >> 24);  //             000000AB
}

void showSwappedVersion(Example& ex)
{
	char hex_string[20];

	sprintf_s(hex_string, "%X", swapU32(ex.m_a)); //convert number to hex
	cout << hex_string << endl;
	sprintf_s(hex_string, "%X", swapU16(ex.m_b)); //convert number to hex
	cout << hex_string << endl;
	sprintf_s(hex_string, "%X", swapU32(ex.m_c)); //convert number to hex
	cout << hex_string << endl;

}

void main()
{
	Example data{ 0xABCD1234,0xEF67,0x890ABCDE };

	showSwappedVersion(data);

}