#include"./include/Score.hpp"
#include<iostream>

Score::Score(int dimension, int square){

  this->dimension = dimension;
  this->square = square;
  
  makeFont();
  makeBorders();
  
}


Score::~Score(){

  std::cout <<"Score deleted\n";
  
}


void Score::setScore(){
  
  ++result;
  myScore.setString(scoreString + std::to_string(result));
  
}


void Score::draw(sf::RenderWindow &window){
  drawScore(window);
  drawBorders(window);
}


void Score::drawScore(sf::RenderWindow &window){
  window.draw(this->myScore);
}


void Score::drawBorders(sf::RenderWindow &window){
  for(int border=0; border<4; border++)
    window.draw(borders[border]);
}


void Score::makeFont(){
  if(!font.loadFromFile("./include/arial.ttf"))
    std::cout <<"error";
  
  this->myScore.setString(this->scoreString + std::to_string(this->result));
  this->myScore.setCharacterSize(32);
  this->myScore.setFillColor(sf::Color::White);
  this->myScore.setPosition(textPosX, textPosY);
  this->myScore.setFont(font);
}


void Score::makeBorders(){

  borders[0].setSize(sf::Vector2f(dimension, square));
  borders[0].setPosition(0, dimension);

  borders[1].setSize(sf::Vector2f(dimension, square));
  borders[1].setPosition(sf::Vector2f(0, dimension+90));

  borders[2].setSize(sf::Vector2f(square, 100));
  borders[2].setPosition(0, dimension);

  borders[3].setSize(sf::Vector2f(square, 100));
  borders[3].setPosition(sf::Vector2f(dimension-10, dimension));

  for(int border=0; border<4; border++)
    borders[border].setFillColor(sf::Color::White);
  
}
