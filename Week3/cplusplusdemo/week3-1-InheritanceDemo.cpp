/** @file week3-1-InheritanceDemo.cpp
 *  @brief Inhertiance Demo
 * 
 *  Inheritance allows new classes to be defined as extensions to preexisting classes
 *  Inheritance creates an “is - a” relationship between classes.
 *  For example, a circle is a type of shape.
 *  We can draw diagrams of class hierarchies using the conventions defined by the Unified Modeling Language(UML).
 *
 *  @attention Go to Visual Studio Installer, search for "Class Designer" and install it!
 *
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
using namespace std;


/// animal is a super class for Mammal and Winged Animal
/// 
/// animals eat
struct Animal {
    /// <summary>
    /// 
    ///The default keyword is introduced in C++ 11. Its use tells the compiler to independently generate the corresponding class function, if one is not declared in the class.
    /// </summary>
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


void main()
{
    // error: which Animal sub-object should a Bat cast into, 
    // a Mammal::Animal or a WingedAnimal::Animal?
    //Animal& a = bat;  

    Animal& mammal = static_cast<Mammal&>(bat);
    Animal& winged = static_cast<WingedAnimal&>(bat);
   
}