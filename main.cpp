#include <iostream>

// AbstractBaseShape.cpp				April 2022
//
// Virtual functions are member functions whose behavior can be overridden in derived classes.
//
// Demonstrates definition of Pure Virtual Functions (=0) in a Base class.
// Defining one (or more) pure virtual functions makes a class an "Abstract class".
// Derived classes (subclasses) must implement all pure virtual functions
// inherited from a Base class.
//
// **** Dynamic Binding - Runtime Binding - Runtime Polymorphism ****
// When the draw() method is called using a pointer of the Base class type (i.e. Shape*)
// it is not known which concrete implementation of the draw() method will be called until runtime
// i.e. (is it draw() for a Circle or draw() for a Rectangle ?)
// (The pointer could be pointing at any class derived from the Base class)
//
// If the object pointed at is a Circle object, then the draw() function that was
// defined in the Circle class is called.
// If the object pointed at is a Rectangle object, then the draw() function
// defined in Rectangle is called.  This is behavior is called
// "Runtime Polymorphism" or "Run Time Binding" or "Late Binding",
// because the version of draw() to call is not known
// until the type of the object is presented. (We can't 'bind' to the draw() method
// until we see what type of object we are presented with.

// **** virtual functions and 'pure' virtual functions ****
//
// An abstract class contains at least one pure virtual function.
// You declare a pure virtual function by using a pure specifier (= 0)
// in the declaration of a virtual member function in the class declaration.
//
// A �virtual function� has a definition/implementation in the Base class and is preceded by the word "virtual".
//     	virtual void draw() { cout << "Drawing a Shape"; }
//
// This tells the compiler that we want to allow derived classes to define their own version of the
// virtual function, and, that we want to use Runtime Polymorphism (runtime binding) when we use
// pointers of the Base class type to point at derived class objects.
//
// A �pure virtual function� is declared in the Base class but with NO implementation, and
// is followed by the 'pure virtual' specifier "=0"
// 	    virtual void draw() = 0;
//
// This tells the compiler that ALL derived classes MUST implement the function.
//
// If a class contains at least one pure virtual function, then that
// class becomes an Abstract Class.  This means that we can NOT instantiate objects
// of this base class type.  (In our example, we can't make Shape objects, because
// Shape is an Abstract class.)
//

#include <iostream>
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

void fillShapesVector(vector<Shape*>& vec);


int main() //  polymorphism in Action - polymorphism ONLY works with POINTERS (or references)
{
    Shape* shapePtr;	// pointer of Base type. Can point at any objects derived from Shape class

    shapePtr = new Circle(2, 3, 40); // object of derived type
    // at this point it is not known (by compiler) whether the shapePtr is pointing at
    // a Circle or at a Rectangle.  At the point where the draw() function is called, then
    // the type of the Object is examined, and the appropriate draw() function is called
    // - in this case the object is a Circle, so th edraw() function defined in the Circle
    // class is called.  (This is sensible behaviour !)

    shapePtr->draw();	// late binding - draw() function determined at runtime
    delete shapePtr;

    shapePtr = new Rectangle(3, 4, 10, 15);
    shapePtr->draw();
    delete shapePtr;

    // Vector of pointers to Shape objects
    vector<Shape*> shapes;

    fillShapesVector(shapes);

    for (Shape* shapePtr : shapes)
    {
        shapePtr->draw();		// polymorphic behaviour
    }

    // finally, we have to free (delete) the dynamically allocated Shape objects
    // pointed at by the pointers in the vector, and clear the vector.
    for (Shape* rShapePtr : shapes)
    {
        delete rShapePtr;	// free the memory;
    }
    shapes.clear(); // clear the contents of the vector as the objects it points to have been freed.

    // Shape s;		// won't be allowed by compiler, can't instantiate an abstract class
    // shapePtr = new Shape();  // won't be allowed
}

void fillShapesVector(vector<Shape*>& vec)
{
    vec.push_back(new Circle(1, 3, 5));	// dynamically allocated Circle object

    vec.push_back(new Rectangle(8, 6, 20, 25));

    // etc.. shapes could be read from a file
}