#include "Shape.cpp"
class Ball: public Shape
{

public:
  int radius;
  Ball(int inX, int inY, int r) : Shape(inX, inY){
    radius=r;
  }
  
};
