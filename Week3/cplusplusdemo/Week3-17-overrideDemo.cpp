/** @file Week3-17-overrideDemo.cpp
 *  @brief Override Demo
 *
 *  In a member function declaration or definition, override specifier ensures that the function is virtual
 *  and is overriding a virtual function from a base class.
 *  The program is ill - formed(a compile - time error is generated) if this is not true.
 *  override is an identifier with a special meaning when used after member function declarators :
 *  it's not a reserved keyword otherwise.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


struct A
{
    virtual void foo();
    void bar();
};

struct B : A
{
   // void foo() const override; // Error: B::foo does not override A::foo (signature mismatch)
    void foo() override; // OK: B::foo overrides A::foo
   // void bar() override; // Error: A::bar is not virtual
    virtual void foo();
};