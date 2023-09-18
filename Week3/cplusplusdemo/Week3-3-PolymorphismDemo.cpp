/** @file Week3-3-PolymorphismDemo.cpp
 *  @brief Polymorphism Demo
 *
 *  Polymorphism allows a collection of objects of different types to be manipulated through a single common interface.
 *  One way to draw this heterogeneous collection of shapes is to use a switch statement.
 *  drawShapes() function needs to “know” about all of the kinds of shapes that can be drawn.
 *  Difficult to add new types of shapes to the system.
 *  The solution is to insulate the majority of our code from any knowledge of the types of objects with which it might be dealing.
 *  A virtual function—the C++ language’s primary polymorphism mechanism.
 *
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */


#include <iostream>
#include <list>
using namespace std;

struct Shape
{
	virtual void Draw() = 0; // pure virtual function
	virtual ~Shape() { } // ensure derived dtors are virtual
};
struct Circle : public Shape
{
	virtual void Draw()
	{
		// draw shape as a circle
		cout << "draw shape as a circle" << endl;
	}
};
struct Rectangle : public Shape
{
	virtual void Draw()
	{
		// draw shape as a rectangle
		cout << "draw shape as a rectangle" << endl;
	}
};
struct Triangle : public Shape
{
	virtual void Draw()
	{
		// draw shape as a triangle
		cout << "draw shape as a triangle" << endl;
	}
};

void drawShapes(std::list<Shape*>& shapes)
{
	std::list<Shape*>::iterator pShape = shapes.begin();
	std::list<Shape*>::iterator pEnd = shapes.end();
	for (; pShape != pEnd; pShape++)
	{
		(*pShape)->Draw(); // call virtual function
	}
}

void main()
{
	Triangle triangle;
	Circle circle;
	Rectangle rectangle;

	triangle.Draw();
	circle.Draw();
	rectangle.Draw();

	std::list<Shape*> shapes;
	shapes.push_back(&triangle);
	shapes.push_back(&circle);
	shapes.push_back(&rectangle);
	drawShapes(shapes);

	std::list<Shape*> shapes2;
	shapes2.push_front(&triangle);
	shapes2.push_front(&circle);
	shapes2.push_front(&rectangle);
	drawShapes(shapes2);
}