// CPP program to illustrate (#) operator
//This operator causes the corresponding actual argument to be enclosed in double quotation marks. 
//The # operator, which is generally called the stringize operator, 
//turns the argument it precedes into a quoted string


#include <stdio.h>
#define makestring(s) #s
int main(void)
{
    printf(makestring(this is a string));
    return 0;
}