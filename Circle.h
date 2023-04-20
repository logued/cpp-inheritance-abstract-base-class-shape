#ifndef INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_CIRCLE_H
#define INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_CIRCLE_H

// Circle.h
//
// Circle is a Derived class because it inherits from the base class Shape

#include "Shape.h"

class Circle : public Shape {   // Circle inherits from Shape.  public inheritance

private:
    int x, y;
    int radius;
public:
    Circle(int x, int y, int radius) {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void draw() override;   // "override" -although not required
                            // - reminds us that this overrides a Base function
    ~Circle() override;

};

#endif //INHERITANCE_SHAPE_ABSTRACT_BASE_CLASS_CIRCLE_H
