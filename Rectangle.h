#include "Shape.h"
#pragma once 
//#ifndef "Shape.h"
//#define "Shape.h"
class Rectangle: public Shape{
public:
  int width, height;
  Rectangle(int inX, int inY, int w, int h) : Shape(inX, inY){ //x and y are left-top corner for drawning rectangle
    width=w;
    height=h;
  }
};
