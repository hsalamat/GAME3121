//When used in a virtual function declaration or definition, 
//final specifier ensures that the function is virtual and specifies 
//that it may not be overridden by derived classes.
struct Base
{
    virtual void foo();
};

struct A : Base
{
    void foo() final; // Base::foo is overridden and A::foo is the final override
    //void bar() final; // Error: bar cannot be final as it is non-virtual
};

struct B final : A // struct B is final
{
    //void foo() override; // Error: foo cannot be overridden as it is final in A
};

struct C : B // Error: B is final
{
};