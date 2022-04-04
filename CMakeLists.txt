cmake_minimum_required(VERSION 3.21)
project(Inheritance_Shape_ABstract_Base_Class)

set(CMAKE_CXX_STANDARD 14)

add_executable(Inheritance_Shape_ABstract_Base_Class main.cpp Shape.cpp Shape.h Rectangle.cpp Rectangle.h Circle.cpp Circle.h)
