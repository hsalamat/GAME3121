#include <iostream>
using namespace std;

/// animal is a super class for Mammal and Winged Animal
/// 
/// animals eat
struct Animal {
    virtual ~Animal() = default;

    ///  Eat function 
    /// 
    /// Eat details...
    virtual void Eat() {}
};

struct Mammal : Animal {
    /// Breathe make our mammal breath
    /// 
    /// @param no parameters
    /// @returns void
    /// @note are you having or what
    /// @attention do not change that function
    /// @warning make sure that you are not passing nullptr to this fucntion
    /// ### Example
    ///  Animal& mammal = static_cast<Mammal&>(bat);
    /// Animal& winged = static_cast<WingedAnimal&>(bat);
    virtual void Breathe() {}
};

struct WingedAnimal : Animal {
    virtual void Flap() {}
};

// A bat is a winged mammal
struct Bat : Mammal, WingedAnimal {};

Bat bat;


/// Inhertiance Demo
/// 
///Inheritance allows new classes to be defined as extensions to preexisting classes
//Inheritance creates an “is - a” relationship between classes.
//For example, a circle is a type of shape.
//We can draw diagrams of class hierarchies using the conventions defined by the Unified Modeling Language(UML).
void main()
{
    // error: which Animal sub-object should a Bat cast into, 
    // a Mammal::Animal or a WingedAnimal::Animal?
    //Animal& a = bat;  

    Animal& mammal = static_cast<Mammal&>(bat);
    Animal& winged = static_cast<WingedAnimal&>(bat);
   
}