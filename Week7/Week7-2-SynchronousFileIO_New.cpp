//Many old CRT (C Runtime Library) functions have newer, more secure versions. 
// If a secure function exists, the older, less secure version is marked as deprecated. 
// The new version has the _s ("secure") suffix.
// This program opens a file that's named FREAD.OUT and
// writes characters to the file. It then tries to open
// FREAD.OUT and read in characters by using fread_s. If the attempt succeeds,
// the program displays the number of actual items read.
//The secure functions don't prevent or correct security errors. Instead, they catch errors when they occur. 
// They do extra checks for error conditions. If there's an error, they invoke an error handler (see Parameter validation).

//For example, the strcpy function can't tell if the string it copies is too large for the destination buffer. 
// Its secure counterpart, strcpy_s, takes the size of the buffer as a parameter. 
// So, it can determine if a buffer overrun will occur. 
// If you use strcpy_s to copy 11 characters into a 10 character buffer, 
// that's an error on your part; strcpy_s can't correct your mistake. 
// But it can detect your error and inform you by invoking the invalid parameter handler.

#include <stdio.h>

#define BUFFERSIZE 30
#define DATASIZE 22
#define ELEMENTCOUNT 2
#define ELEMENTSIZE (DATASIZE/ELEMENTCOUNT)
#define FILENAME "FREAD.OUT"

int main(void)
{
    FILE* stream;
    char list[30];
    int  i, numread, numwritten;

    for (i = 0; i < DATASIZE; i++)
        list[i] = (char)('z' - i);
    list[DATASIZE] = '\0'; // terminal null so we can print it

    // Open file in text mode:
    if (fopen_s(&stream, FILENAME, "w+t") == 0)
    {
        // Write DATASIZE characters to stream
        printf("Contents of buffer before write/read:\n\t%s\n\n", list);
        numwritten = fwrite(list, sizeof(char), DATASIZE, stream);
        printf("Wrote %d items\n\n", numwritten);
        fclose(stream);
    }
    else {
        printf("Problem opening the file\n");
        return -1;
    }

    if (fopen_s(&stream, FILENAME, "r+t") == 0) {
        // Attempt to read in characters in 2 blocks of 11
        numread = fread_s(list, BUFFERSIZE, ELEMENTSIZE, ELEMENTCOUNT, stream);
        printf("Number of %d-byte elements read = %d\n\n", ELEMENTSIZE, numread);
        printf("Contents of buffer after write/read:\n\t%s\n", list);
        fclose(stream);
    }
    else {
        printf("File could not be opened\n");
        return -1;
    }
}