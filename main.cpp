#include<SFML/Graphics.hpp>
#include<iostream>
#include"Snake.cpp"
#include<thread>
#include<unistd.h>

void drawCircle(bool show);
void makeMesh();
void refresh();
void drawSnake(Snake snake);
bool contains(Snake snake, sf::RectangleShape rec);

const int dimension = 800;
const int width = dimension;
const int height = dimension + 100;

const int amount = 80;
const int square = (dimension/amount);


sf::Color tileColor(100, 255, 210, 255);
sf::Color foodColor(0, 0, 0, 255);
sf::Color snakeColor(0, 0, 0, 255);

sf::RectangleShape rec(sf::Vector2f(square, square));
sf::Vector2f tilePos;
sf::RectangleShape mesh[amount][amount];

sf::CircleShape cir(22);

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

int main(){
  Snake snake;

  makeMesh();
  rec.setPosition(120, 120);
  bool showCircle = false;
  
  //cir.setFillColor(foodColor);
  rec.setFillColor(sf::Color(0,0,0,255));
  
  while(window.isOpen()){
    sf::Event event;

    while(window.pollEvent(event)){
      
      if(event.type == sf::Event::Closed)
	window.close();

      else if(event.type == sf::Event::KeyPressed){
	//std::cout << "Pressed \n" << showCircle;

	tilePos = rec.getPosition();
	
	if(event.key.code == sf::Keyboard::A){
	  //rec.setPosition(tilePos.x - square, tilePos.y);
	  snake.setToward(-10, 0);
	}else if(event.key.code == sf::Keyboard::D){
	  //rec.setPosition(tilePos.x + square, tilePos.y);
	  snake.setToward(10, 0);
	}else if(event.key.code == sf::Keyboard::W){
	  //rec.setPosition(tilePos.x, tilePos.y - square);
	  snake.setToward(0, -10);
	}else if(event.key.code == sf::Keyboard::S){
	  //rec.setPosition(tilePos.x, tilePos.y + square);
	  snake.setToward(0, 10);
	}else if(event.key.code == sf::Keyboard::Enter){
	  //snake.setPosition();
	  std::cout<<snake.getHeadX() << " " << snake.getHeadY() << "\n";
	}
	
      }
      
    }

    window.clear();

    //window.draw(cir);
    refresh();
    //drawCircle(showCircle);
    window.draw(rec);
    drawSnake(snake);

    if(contains(snake, rec)){
      snake.resizeBody();
    }
    
    window.display();
    if(snake.isCollision()){
      window.close();
    }

    //std::thread thread(drawSnake(rec));
    snake.setPosition();
    usleep(100000);
   
  }
  //thread.join();
  return 0;
}

void makeMesh(){
  int posX = 0, posY = 0;
  std::cout << square << " " << amount << "\n";
  for(int row=0; row<amount; row++){
    for(int col=0; col<amount; col++){

      //std::cout << "posX " << posX << " posY " << posY << "\n";
      mesh[row][col].setSize(sf::Vector2f(square, square));

      if ( !(col == 0 || col == amount-1 || row == 0 || row == amount-1) ){
	mesh[row][col].setFillColor(tileColor);
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

void drawSnake(Snake snake){
  //snake.setPosition();
  for(int part=0; part<snake.body.size(); part++){
    //mesh[snake.body.at(part).getPosition().x][snake.body.at(part).getPosition().y].setFillColor(snakeColor);
    //std::cout << "Draw snake";
    snake.body.at(part).setFillColor(snakeColor);
    window.draw(snake.body.at(part));
    //window.draw(mesh[snake.body.at(part).at(0)][snake.body.at(part).at(0)]);
  }
}

bool contains(Snake snake, sf::RectangleShape rec){
  if(snake.getHeadX() == rec.getPosition().x && snake.getHeadY() == rec.getPosition().y)
    return true;
  return false;
}

void refresh(){
  for(int row=0; row<amount; row++){
    for(int col=0; col<amount; col++){
      window.draw(mesh[row][col]);
    }
  }
}

void drawRec( sf::RectangleShape rec ){
  while(true)
    window.draw(rec);
}

void drawCircle(bool show){
  if(show == true){
    window.draw(cir);
  }
  //  return ;
}
