//A macro is a fragment of code which has been given a name.
//Whenever the name is used, it is replaced by the contents of the macro.
//There are two kinds of macros.They differ mostly in what they look like when they are used.
//Object - like macros resemble data objects when used
// example: 
#define BUFFER_SIZE 1024
//function - like macros resemble function calls.


#include <iostream>
using namespace std;

#define MAX(i, j) (((i) > (j)) ? i : j)

int main()
{
    int a, b;

    a = 250;
    b = 25;

    cout << "The maximum is " << MAX(a, b) << endl;

    return 0;
}