#ifndef INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H
#define INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H

// Shape.h
// Shape is the Base class in this sample.
// It became an Abstract class, because it contains a
// pure virtual function draw()=0 (with no implementation).
// We cannot make an instance of Shape because it contains a pure virtual function.
//
// Every class that derives from Shape will be forced to implement the draw() method.

class Shape {

public:
    virtual void draw() =0;  // the "=0" makes this a "pure virtual function"

    // "virtual" => it MUST be implemented by ALL subclasses
    // "=0" makes this virtual function PURE specifying that there is
    //  no implementation of draw() to be inherited,
    //  and hence, derived classes must implement it.

    virtual ~Shape();		  // virtual destructor
    // The destructor is declared as virtual so that it can be overridden
    // in derived classes, as necessary.

};

#endif //INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H
