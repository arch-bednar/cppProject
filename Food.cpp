#include"./include/Food.hpp"
#include<iostream>

Food::~Food(){

  std::cout<<"Food deleted\n";
  
}

int Food::getX(){

  return this->getPosition().x;
  
}

int Food::getY(){

  return this->getPosition().y;
  
}

void Food::changePos(int x, int y){

  this->setPosition(x, y);
  
}

bool Food::isEaten(int x, int y){

  if(getX() == x && getY() == y)
    return true;
  return false;
}

