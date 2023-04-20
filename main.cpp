#include <iostream>

// AbstractBaseShape.cpp				20th April 2023
//
// Virtual functions are member functions whose behavior can be
// overridden in derived classes. A function can only be overridden
// if it is virtual.
//
// If a virtual function is declared as pure (using =0), then
// the class becomes an Abstract class and can not be instantiated.
//
// Demonstrates definition of Pure Virtual Functions (=0) in a Base class.
// Defining one (or more) pure virtual functions makes a class an "Abstract class".
// Derived classes (subclasses) must implement all pure virtual functions
// inherited from their Base class.
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
// defined in Rectangle is called.  This is behavior is called -
// "Runtime Polymorphism" or "Run Time Binding" or "Late Binding",
// because the version of draw() to call is not known
// until the type of the object is presented. (We can't 'bind' to the draw() method
// until we see what type of object we are presented with, and thus which draw()
// implementation to call

// **** virtual functions and 'pure' virtual functions ****
//
// An abstract class contains at least one pure virtual function.
// You declare a pure virtual function by using a pure specifier (= 0)
// in the declaration of a virtual member function in the class declaration.
//
// A "virtual function" has a definition/implementation in the Base class and
// is preceded by the word "virtual".
//     	virtual void draw() { cout << "Drawing a Shape"; }
//
// This tells the compiler that we want to allow derived classes to define their own version of the
// virtual function, and, that we want to use Runtime Polymorphism (runtime binding) when we use
// pointers of the Base class type to point at derived class objects.
//
// A "pure virtual function" is declared in the Base class but with NO implementation, and
// is followed by the 'pure virtual' specifier "=0"
// 	    virtual void draw() =0;
//
// This tells the compiler that ALL derived classes MUST implement the function.
//
// If a class contains at least one pure virtual function, then that
// class becomes an Abstract Class.  This means that we can NOT instantiate objects
// of this base class type.  (In our example, we can't make Shape objects, because
// Shape is an Abstract class.)
//                                  [note, some duplication in above needs to be removed]

#include <iostream>
#include <vector>

#include "Circle.h"
#include "Shape.h"
#include "Rectangle.h"

using namespace std;

void fillShapesVector(vector<Shape*>& vec); // function prototype


int main() //  polymorphism in Action - polymorphism ONLY works with POINTERS (or references)
{
    Shape* shapePtr;	// pointer of Base type. Can point at any objects derived from Shape class

    shapePtr = nullptr;
    // at this point it is not known (by the compiler) whether the shapePtr is pointing at
    // a Circle or at a Rectangle. It could point to either.

    shapePtr = new Circle(2, 3, 40);    // object of derived type


    shapePtr->draw();	// late binding - draw() function determined at runtime
    // At the point where the draw() function is called,
    // the type of the Object is examined, and the appropriate draw() function is called
    // - in this case the object is a Circle, so the draw() function defined in the Circle
    // class is called.  This is called "late binding" or "dynamic binding".
    // (This is sensible behaviour !)

    delete shapePtr;    // free the memory

    shapePtr = new Rectangle(3, 4, 10, 15);

    shapePtr->draw();   // dynamically binds to the draw() method of the Rectangle class

    delete shapePtr;    // free up the memory occupied by Rectangle object

    // Vector of pointers to Shape objects
    // Each pointer in the vector can point at any derived class object
    // that derived from the Shape class.  (e.g. Circle or Rectangle)
    vector<Shape*> shapes_vector;

    fillShapesVector(shapes_vector);

    for (Shape* shapePtr : shapes_vector)
    {
        shapePtr->draw();		// polymorphic behaviour, uses dynamic binding
    }

    // finally, we have to free (delete) the dynamically allocated Shape objects
    // pointed at by the pointers in the vector, and clear the vector.
    for (Shape* ptr : shapes_vector)
    {
        delete ptr;	// free the memory;
    }

    shapes_vector.clear(); // clear the contents of the vector as the objects they point to have been deleted (freed)

    // Shape s;		// won't be allowed by compiler, can't instantiate an abstract class
    // shapePtr = new Shape();  // won't be allowed
}

// Using a reference to the shapes vector
// instantiate two objects and add them to the vector.
//
void fillShapesVector(vector<Shape*>& vec)  // reference to a vector
{
    vec.push_back(new Circle(1, 3, 5));	// dynamically allocated Circle object

    vec.push_back(new Rectangle(8, 6, 20, 25));

    // etc.. shapes could be read from a file
}