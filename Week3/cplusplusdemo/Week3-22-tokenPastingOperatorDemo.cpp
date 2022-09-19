// CPP program to illustrate (##) operator
//Token-pasting operator (##)
//Allows tokens used as actual arguments to be concatenated to form other tokens.
// It is often useful to merge two tokens into one while expanding macros.
// This is called token pasting or token concatenation.The ‘##’ pre - processing operator performs token pasting.
// When a macro is expanded, the two tokens on either side of each ‘##’ operator are combined into a single token, 
// which then replaces the ‘##’and the two original tokens in the macro expansion.
//Examples :
//The preprocessor transforms printf("%d", concat(x, y)); into printf("%d", xy)


#include <stdio.h>
#define concat(a, b) a##b
int main(void)
{
    int xy = 30;
    printf("%d", concat(x, y));
    return 0;
}