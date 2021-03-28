#include<iostream>

class Shape
{
public:
  int x,y;
  Shape(int inX, int inY){
    x=inX;
    y=inY;
  }

  int getX() {
    return x;
  }

  int getY() {
    return y;
  }

  void setX(int temp){
    x=temp;
  }

  void setY(int temp){
    y=temp;
  }
};
