//an IEEE - 754 floating - point value has a detailed internal structure
//involving some bits for the mantissa, some bits for the exponent and a
//sign bit.However, you can endian - swap it just as if it were an integer, because bytes are bytes.


#include <iostream>
#include <cassert>
using namespace std;

typedef float F32;
typedef unsigned int U32;
typedef unsigned short U16;
typedef unsigned char U8;


inline U32 swapU32(U32 value)
{
	return ((value & 0x000000FF) << 24)
		| ((value & 0x0000FF00) << 8)
		| ((value & 0x00FF0000) >> 8)
		| ((value & 0xFF000000) >> 24);
}

union U32F32
{
	U32 m_asU32;
	F32 m_asF32;
};

inline F32 swapF32(F32 value)
{
	U32F32 u;
	u.m_asF32 = value;
	// endian-swap as integer
	u.m_asU32 = swapU32(u.m_asU32);
	return u.m_asF32;
}

void showSwappedVersion(U32F32& ex)
{
	char hex_string[20];
	U32F32 result;
	result.m_asF32 = swapF32(ex.m_asF32);

	sprintf_s(hex_string, "%X", result.m_asU32); //convert number to hex
	cout << hex_string << endl;


	assert(CHAR_BIT * sizeof(float) == 32);

	//does the samething as above!
	//float x;
	//const unsigned char* pf = reinterpret_cast<const unsigned char*>(&result.m_asF32);

	//for (size_t i = 0; i != sizeof(float); ++i)
	//{
	//	// ith byte is pf[i]
	//	 printf("0x%X ", pf[i]);
	//}

}

void main()
{
	U32F32 data;
	data.m_asU32 = 0xABCD1234;

	showSwappedVersion(data);

}