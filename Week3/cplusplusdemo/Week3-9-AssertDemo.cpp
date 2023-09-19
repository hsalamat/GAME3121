/** @file Week3-9-AssertDemo.cpp
 *  @brief Assert Demo
 *
 *  Assertions are lines of error-checking code that are inserted to catch logical
 *  mistakes and violations of the programmer’s original assumptions.
 *  Assertion checks are usually stripped out of the final production build
 *  of the game.
 * 
 *  An assertion is a line of code that checks an expression. If the expression evaluates
 *  to true, nothing happens. But if the expression evaluates to false, the
 *  program is stopped, a message is printed and the debugger is invoked if possible.
 *  
 *  They act like land mines for bugs.
 * 
 *  @attention The assert() needs to be executable at runtime, and one can’t even put executable code at global
 *  scope in a .cpp file outside of a function definition. The solution to this problem
 *  is a compile-time assertion, also known as a static assertion.
 *  Starting with C++11, the standard library defines a macro named
 *  static_assert() for us. So we can re-write the example above as follows:
 *  struct NeedsToBe128Bytes
 *  {
 *  U32 m_a;
 *  F32 m_b;
 *  // etc.
 *  };
 *  static_assert(sizeof(NeedsToBe128Bytes) == 128, "wrong size");
 * 
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
// uncomment to disable assert()
//#define NDEBUG
#include <cassert>

// Assert with message! Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))

int main()
{

        assert(2 + 2 == 4);
        std::cout << "Execution continues past the first assert\n";
        assert(("this is right too", 2 + 2 == 4));

        assertm(2 + 2 == 5, "This is wrong");
        std::cout << "Execution continues past the second assert\n";
        assert((2 * 2 == 4) && "Yet another way to add assert message");

}