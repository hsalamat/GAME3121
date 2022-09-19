//C language uses macro. The preprocessor replace all macro calls directly within the macro code. 
//It is recommended to always use inline function instead of macro. According to Dr. Bjarne Stroustrup the creator of C++ 
//that macros are almost never necessary in C++ and they are error prone. There are some problems with the use of macros 
//in C++. Macro cannot access private members of class. Macros looks like function call but they are actually not.
///Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances like:
//1) If a function contains a loop. (for, while, do - while)
//2) If a function contains static variables.
//3) If a function is recursive.
//4) If a function return type is other than void, and the return statement doesn’t exist in function body.
//5) If a function contains switch or goto statement.

//Inline functions provide following advantages :
//1) Function call overhead doesn’t occur.
//2) It also saves the overhead of push / pop variables on the stack when function is called.
//3) It also saves overhead of a return call from a function.
//4) When you inline a function, you may enable compiler to perform context specific optimization on the body of function.Such optimizations are not possible for normal function calls.Other optimizations can be obtained by considering the flows of calling contextand the called context.
//5) Inline function may be useful(if it is small) for embedded systems because inline can yield less code than the function call preambleand return.

#include <iostream>
using namespace std;
class operation
{
    int a, b, add, sub, mul;
    float div;
public:
    void get();
    void sum();
    void difference();
    void product();
    void division();
};
inline void operation::get()
{
    cout << "Enter first value:";
    cin >> a;
    cout << "Enter second value:";
    cin >> b;
}

inline void operation::sum()
{
    add = a + b;
    cout << "Addition of two numbers: " << a + b << "\n";
}

inline void operation::difference()
{
    sub = a - b;
    cout << "Difference of two numbers: " << a - b << "\n";
}

inline void operation::product()
{
    mul = a * b;
    cout << "Product of two numbers: " << a * b << "\n";
}

inline void operation::division()
{
    div = a / b;
    cout << "Division of two numbers: " << a / b << "\n";
}

int main()
{
    cout << "Program using inline function\n";
    operation s;
    s.get();
    s.sum();
    s.difference();
    s.product();
    s.division();
    return 0;
}