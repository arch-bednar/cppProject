#include<SFML/Graphics.hpp>
#include"Snake.cpp"
#include"Food.cpp"
#include"Score.cpp"
#include"Board.cpp"
#include<unistd.h>
#include<stdlib.h>


void makeMesh();
void refresh();
void genFood();
bool isCorrect(int x, int y);

const int dimension = 800;
const int width = dimension;
const int height = dimension + 100;

const int amount = 80;
const int square = (dimension/amount);

sf::RectangleShape deadCell(sf::Vector2f(square, square));

sf::RenderWindow window(sf::VideoMode(width, height), "SFML Snake by Dejv", sf::Style::Titlebar | sf::Style::Close);

Food food(square, square);
Board board;
Score score(dimension, square);
Snake snake;

int main(){

  genFood();

  while(window.isOpen()){
    sf::Event event;

    while(window.pollEvent(event)){
      
      if(event.type == sf::Event::Closed)
	window.close();

      else if(event.type == sf::Event::KeyPressed){

	if(event.key.code == sf::Keyboard::A){

	  if(snake.getTowardX() != 10 && snake.getTowardY() != 0)
	    snake.setToward(-10, 0);
	  
	}else if(event.key.code == sf::Keyboard::D){

	  if(snake.getTowardX() != -10 && snake.getTowardY() != 0)
	    snake.setToward(10, 0);
	  
	}else if(event.key.code == sf::Keyboard::W){

	  if(snake.getTowardX() != 0 && snake.getTowardY() != 10)
	    snake.setToward(0, -10);
	  
	}else if(event.key.code == sf::Keyboard::S){

	  if(snake.getTowardX() != 0 && snake.getTowardY() != -10)
	    snake.setToward(0, 10);
	}	  
      }
      
    }

    window.clear();
    score.draw(window);
    board.draw(window);
    window.draw(food);
    snake.draw(window);

    
    if(food.isEaten(snake.getHeadX(), snake.getHeadY())){
      score.setScore();
      snake.resizeBody();
      genFood();
    }

    if(!snake.isDead && snake.isCollision()){
      snake.isDead = true;
      deadCell.setPosition(snake.getHeadX(), snake.getHeadY());
      deadCell.setFillColor(sf::Color::Red);
    }
    
    if(snake.isDead){
      window.draw(deadCell);
      window.display();
      continue;
    }


    snake.setPosition();
    window.display();
    usleep(90000);
   
  }

  return 0;

}


void genFood(){

  int x,y;
  srand(time(NULL));
  
  do{
    x = rand() % 780 + 1;
    y = rand() % 780 + 1;
  }while(!isCorrect(x, y));

  food.changePos(x, y);
  
}


bool isCorrect(int x, int y){

  if(x%10!=0 || y%10!=0 || x<10 || y < 10)
    return false;

  for(int part=0; part < snake.body.size(); part++){
    if(snake.body.at(part).getPosition().x == x &&
       snake.body.at(part).getPosition().y == y) { return false; }
  }

  return true;
  
}
