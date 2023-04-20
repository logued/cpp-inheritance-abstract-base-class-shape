// Shape.cpp

#include "Shape.h"
#include<iostream>

using namespace std;

//Implementation of the virtual destructor

Shape::~Shape() {
    cout << "~Shape() called. The Shape base destructor is called after derived destructor.\n";
}

