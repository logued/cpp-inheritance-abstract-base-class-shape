// Rectangle.cpp

#include "Rectangle.h"
#include <iostream>
using namespace std;

void Rectangle::draw() {	// implementation of draw()
    cout << "drawing a Rectangle...\ndone drawing." << endl;
}

Rectangle::~Rectangle() { cout << "~Rectangle() destructor called.\n"; }
