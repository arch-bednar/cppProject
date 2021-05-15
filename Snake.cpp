#include "./include/Snake.hpp"

Snake::Snake(){

  body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
  body.back().setPosition(40, 40);

  body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
  body.back().setPosition(40, 30);

  body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
  body.back().setPosition(40, 20);

}

Snake::~Snake(){

}

void Snake::setPosition(){

  int tempX, tempY, tX, tY;
  tempX = body.front().getPosition().x;
  tempY = body.front().getPosition().y;

  body.at(0).setPosition(tempX+getTowardX(), tempY+getTowardY());

  for( int part=1; part<body.size(); part++){
    tX = body.at(part).getPosition().x;
    tY = body.at(part).getPosition().y;

    body.at(part).setPosition(tempX, tempY);

    tempX = tX;
    tempY = tY;
  }
  
}


void Snake::draw(sf::RenderWindow &window){
  for(int part=0; part<this->body.size(); part++){
    body.at(part).setFillColor(sf::Color::Black);
    window.draw(body.at(part));
  }
}


void Snake::resizeBody(){
  int lastX, lastY;
  lastX = body.back().getPosition().x;
  lastY = body.back().getPosition().y;

  this->setPosition();

  body.push_back(sf::RectangleShape(sf::Vector2f(10, 10)));
  body.back().setPosition(lastX, lastY);
}


bool Snake::isCollision(){

  int headX, headY;
  headX = body.front().getPosition().x;
  headY = body.front().getPosition().y;

  for( int part=1; part<body.size(); part++){
    if(headX == body.at(part).getPosition().x && headY == body.at(part).getPosition().y){
      return true;
    }
  }

  if(headX == 0 || headX == 790){
    return true;
  }else if(headY == 0 || headY == 790){
    return true;
  }
  
  return false;
  
}


int Snake::getHeadX(){
  return body.at(0).getPosition().x;
}


int Snake::getHeadY(){
  return body.at(0).getPosition().y;
}


int Snake::getLastX(){
  return body.back().getPosition().x;
}


int Snake::getLastY(){
  return body.back().getPosition().y;
}


int Snake::getTowardX(){
  return this->toward[0];
}


int Snake::getTowardY(){
  return this->toward[1];
}


void Snake::setToward(int x, int y){
  this->toward[0] = x;
  this->toward[1] = y;
}


void Snake::setDeadHead(){
  body.at(0).setFillColor(sf::Color::Red);
  this->isDead=true;
}
