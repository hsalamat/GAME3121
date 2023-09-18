/** @file Week3-4-MixInClassDemo.cpp
 *  @brief Mix in Classes Demo
 *
 *  Mix in Classes contains methods for use by other classes without having to be the parent class of those other classes.
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <list>
using namespace std;

struct Animator
{
	virtual void Animate(){}
};

struct Shape
{
	virtual void Draw() = 0; // pure virtual function
	virtual ~Shape() { } // ensure derived dtors are virtual
};
struct Circle : public Shape, Animator
{
	virtual void Draw()
	{
		// draw shape as a circle
		cout << "draw shape as a circle" << endl;
	}
};
struct Rectangle : public Shape, Animator
{
	virtual void Draw()
	{
		// draw shape as a rectangle
		cout << "draw shape as a rectangle" << endl;
	}
};
struct Triangle : public Shape, Animator
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

	triangle.Animate();
	circle.Animate();
	rectangle.Animate();

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