#include"./include/Food.hpp"

int Food::getX(){
  return this->getPosition().x;
}

int Food::getY(){
  return this->getPosition().y;
}

void Food::changePos(int x, int y){
  this->setPosition(x, y);
}
