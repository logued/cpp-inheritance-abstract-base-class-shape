#ifndef INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H
#define INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H

// Shape.h
// Shape is the Base class in this sample.
// It is an Abstract class, because it contains a
// pure virtual function (=0) (with no implementation).
// We cannot make an instance of Shape because it contains a pure virtual function.
//
// Every class that derives from Shape must implement the draw() method.

class Shape {

public:
    virtual void draw() = 0;  // the "=0" makes this a "pure virtual function"

    // "virtual" => it MUST be implemented by ALL subclasses
    // "=0" makes this virtual function PURE so no implementation in this class

    virtual ~Shape();		  // virtual destructor
};

#endif //INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_SHAPE_H
