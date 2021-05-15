#include"./include/Board.hpp"

Board::Board(){
  makeMesh();
}


Board::~Board(){

}


void Board::fillRed(int x, int y){
  //mesh[x][y].setFillColor(sf::Color::Red);
  for(int row=0; row<amount-1; row++){
    for(int col=0; col<amount-1; col++){
      if(mesh[row][col].getPosition().x == x &&
	 mesh[row][col].getPosition().y == y){
	mesh[row][col].setFillColor(sf::Color::Red);
	col = amount;
	row = amount;
      }
    }
  }
}


void Board::makeMesh(){

  int posX=0;
  int posY=0;

  for(int row=0; row<this->amount; row++){
    for(int col=0; col<this->amount; col++){
      
      mesh[row][col].setSize(sf::Vector2f(square, square));

      if( !(col == 0 || col == amount-1 || row == 0 || row == amount-1) ){
	mesh[row][col].setFillColor(sf::Color(100, 255, 210, 255));
      }else{
	mesh[row][col].setFillColor(sf::Color(0, 0, 0, 255));
      }

      mesh[row][col].setPosition(posX, posY);
      posX = posX + square;
    }

    posY = posY + square;
    posX = 0;
  }
  
}


void Board::draw(sf::RenderWindow &window){

  for(int row=0; row<amount; row++){
    for(int col=0; col<amount; col++){
      window.draw(mesh[row][col]);
    }
  }
}
