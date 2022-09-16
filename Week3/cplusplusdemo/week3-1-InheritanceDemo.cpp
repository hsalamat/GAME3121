///Inheritance allows new classes to be defined as extensions to preexisting classes
//Inheritance creates an “is - a” relationship between classes.
//For example, a circle is a type of shape.
//We can draw diagrams of class hierarchies using the conventions defined by the Unified Modeling Language(UML).



#include <iostream>
using namespace std;

struct Animal {
    virtual ~Animal() = default;
    virtual void Eat() {}
};

struct Mammal : Animal {
    virtual void Breathe() {}
};

struct WingedAnimal : Animal {
    virtual void Flap() {}
};

// A bat is a winged mammal
struct Bat : Mammal, WingedAnimal {};

Bat bat;



void main()
{
    // error: which Animal sub-object should a Bat cast into, 
    // a Mammal::Animal or a WingedAnimal::Animal?
    //Animal& a = bat;  

    Animal& mammal = static_cast<Mammal&>(bat);
    Animal& winged = static_cast<WingedAnimal&>(bat);
   
}