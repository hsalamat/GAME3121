///https://en.wikipedia.org/wiki/Virtual_inheritance
///Virtual inheritance is a C++ technique that ensures only one copy of a base class's member variables are inherited 
///by grandchild derived classes.

#include <iostream>
using namespace std;

struct Animal {
    virtual ~Animal() = default;
    virtual void Eat() {}
};

// Two classes virtually inheriting Animal:
struct Mammal : virtual Animal {
     void Breathe() {}
};

struct WingedAnimal : virtual Animal {
    virtual void Flap() {}
};

// A bat is a winged mammal
struct Bat : Mammal, WingedAnimal {};

Bat bat;



void main()
{
    // No more error: which Animal sub-object should a Bat cast into, 
    // a Mammal::Animal or a WingedAnimal::Animal?
    Animal& a = bat;  

    //no need for this
    //Animal& mammal = static_cast<Mammal&>(bat);
    //Animal& winged = static_cast<WingedAnimal&>(bat);    

}