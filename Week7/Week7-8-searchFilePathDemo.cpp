#include <windows.h>
#include <iostream>
#include "Shlwapi.h"

using namespace std;

#pragma comment(lib,"Shlwapi.lib")

void main(void)
{
    // Valid file path name (file is there).

    LPCSTR lpStr1 = "C:\\\\Test\\file.txt";

    // Invalid file path name (file is not there).
    LPCSTR lpStr2 = "C:\\\\Test\\file.doc";

    // Return value from "PathFileExists".
    int retval;

    // Search for the presence of a file with a true result.
    retval = PathFileExistsA(lpStr1);
    if (retval == 1)
    {
        cout << "Search for the file path of : " << lpStr1 << endl;
        cout << "The file requested \"" << lpStr1 << "\" is a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }

    else
    {
        cout << "\nThe file requested " << lpStr1 << " is not a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }

    // Search for the presence of a file with a false result.
    retval = PathFileExists((LPCWSTR)lpStr2);

    if (retval == 1)
    {
        cout << "\nThe file requested " << lpStr2 << "is a valid file" << endl;
        cout << "Search for the file path of : " << lpStr2 << endl;
        cout << "The return from function is : " << retval << endl;
    }
    else
    {
        cout << "\nThe file requested \"" << lpStr2 << "\" is not a valid file" << endl;
        cout << "The return from function is : " << retval << endl;
    }
}