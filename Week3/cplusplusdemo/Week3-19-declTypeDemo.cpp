/** @file Week3-19-declTypeDemo.cpp
 *  @brief declType Demo
 *
 *  DeclType Yields the type of its operand, which is not evaluated.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <vector>
int x = 42;
std::vector<decltype(x)> v(100, x); // v is a vector<int>

struct S {
    int x = 42;
};
const S s;
decltype(s.x) y; // y has type int, even though s.x is const

//C++14

const int x = 123;
auto y = x;           // y has type int
decltype(auto) z = x; // z has type const int, the declared type of x