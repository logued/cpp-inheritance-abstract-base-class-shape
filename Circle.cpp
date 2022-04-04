// Circle.cpp
// Implementation of the Circle class.

#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::draw() {	    // implementation of draw
    cout << "drawing a Circle...\ndone drawing." << endl;
}

Circle::~Circle() { cout << "~Circle() destructor called.\n"; }
