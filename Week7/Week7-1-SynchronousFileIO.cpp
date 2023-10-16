//Right click on your file in the solution explorer, select properties,
//and add _CRT_SECURE_NO_WARNINGS in your preprocessor defintion under C/C++
//fopen is deprecated!

#include <stdio.h>

typedef char U8;

bool syncReadFile(const char* filePath,
	U8* buffer,
	size_t bufferSize,
	size_t& rBytesRead)
{
	FILE* handle = fopen(filePath, "rb");
	if (handle)
	{
		// BLOCK here until all data has been read.
		size_t bytesRead = fread(buffer, 1,bufferSize, handle);
		int err = ferror(handle); // get error if any
		fclose(handle);
		if (0 == err)
		{
			rBytesRead = bytesRead;
			return true;
		}
	}
	rBytesRead = 0;
	return false;
}
void main(int argc, const char* argv[])
{
	U8 testBuffer[512];
	size_t bytesRead = 0;
	if (syncReadFile("C:\\Windows\\System32\\d3dx10.dll",
		testBuffer, sizeof(testBuffer),
		bytesRead))
	{
		printf("success: read %u bytes\n", bytesRead);
		// contents of buffer can be used here...
	}
}