//Code after using Abstract factory pattern
// Abstract factory pattern provides a framework that allows to create objects that follows a pattern. 
// AbstractFactory : Declares an interface for operations that create abstract product objects.
//ConcreteFactory: Implements the operations declared in the Abstract Factory to create concrete product objects.
//Product : Defines a product object to be created by the corresponding concrete factoryand implements the AbstractProduct interface.
//Client : Uses only interfaces declared by Abstract Factoryand Abstract Product classes.
// So at runtime, abstract factory is coupled with any desired factory which can create objects of desired type
//There are 5 components:
//
//WINDOWS is defined using C++ preprocessing directive
//Widget class represents the parent class for the products
//We have 4 different product classes : LinuxButton, LinuxMenu, WindowsMenu and WindowsButton
//There is an additional Factory class which handles the error checking 
// and creates the platform specific product(Widget) depending on the platform defined.
//The client does not care which concrete objects it gets from each of these concrete factories 
//since it uses only the generic interfaces of their products.

#include <iostream>
#define WINDOWS

using namespace std;

/**
 * Abstract base product. It should define an interface
 * which will be common to all products. Clients will
 * work with products through this interface, so it
 * should be sufficient to use all products.
 */
class Widget
{
public:
    virtual void draw() = 0;
};

/**
 * Concrete product family 1.
 */
class LinuxButton : public Widget
{
public:
    void draw() { cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget
{
public:
    void draw() { cout << "LinuxMenu\n"; }
};

/**
 * Concrete product family 2.
 */
class WindowsButton : public Widget
{
public:
    void draw() { cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget
{
public:
    void draw() { cout << "WindowsMenu\n"; }
};

/**
 * Abstract factory defines methods to create all
 * related products.
 */
class Factory
{
public:
    virtual Widget* create_button() = 0;
    virtual Widget* create_menu() = 0;
};

/**
 * Each concrete factory corresponds to one product
 * family. It creates all possible products of
 * one kind.
 */
class LinuxFactory : public Factory
{
public:
    Widget* create_button()
    {
        return new LinuxButton;
    }
    Widget* create_menu()
    {
        return new LinuxMenu;
    }
};

/**
 * Concrete factory creates concrete products, but
 * returns them as abstract.
 */
class WindowsFactory : public Factory
{
public:
    Widget* create_button()
    {
        return new WindowsButton;
    }
    Widget* create_menu()
    {
        return new WindowsMenu;
    }
};

/**
 * Client receives a factory object from its creator.
 *
 * All clients work with factories through abstract
 * interface. They don't know concrete classes of
 * factories. Because of this, you can interchange
 * concrete factories without breaking clients.
 *
 * Clients don't know the concrete classes of created
 * products either, since abstract factory methods
 * returns abstract products.
 */
class Client
{
private:
    Factory* factory;

public:
    Client(Factory* f)
    {
        factory = f;
    }

    void draw()
    {
        Widget* w = factory->create_button();
        w->draw();
        display_window_one();
        display_window_two();
    }

    void display_window_one()
    {
        Widget* w[] = {
            factory->create_button(),
            factory->create_menu()
        };
        w[0]->draw();
        w[1]->draw();
    }

    void display_window_two()
    {
        Widget* w[] =
        {
            factory->create_menu(),
            factory->create_button()
        };
        w[0]->draw();
        w[1]->draw();
    }
};

/**
 * Now the nasty switch statement is needed only once to
 * pick and create a proper factory. Usually that's
 * happening somewhere in program initialization code.
 */
int main()
{
    Factory* factory;
#ifdef LINUX
    factory = new LinuxFactory;
#else // WINDOWS
    factory = new WindowsFactory;
#endif

    Client* c = new Client(factory);
    c->draw();
}
