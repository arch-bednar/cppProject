#include "Rectangle.h"

class Board: public Rectangle
{
public:
  Board(int inX, int inY, int w, int h) : Rectangle(inX, inY, w ,h){ };
  void move(int newX){
    x=newX;
  }
};
