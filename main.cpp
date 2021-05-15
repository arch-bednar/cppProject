#include<SFML/Graphics.hpp>
#include<iostream>
#include"Snake.cpp"
#include"Food.cpp"
#include<unistd.h>
#include<stdlib.h>
#include<string>

void drawCircle(bool show);
void makeMesh();
void refresh();
void drawSnake(Snake snake);
bool contains(Snake snake, sf::RectangleShape rec);
void genFood();
bool isCorrect(int x, int y);
void makeBorders();
void drawBorders();

const int dimension = 800;
const int width = dimension;
const int height = dimension + 100;

const int amount = 80;
const int square = (dimension/amount);

int result=0;

int textPosX = 350;
int textPosY = 830;

sf::Color tileColor(100, 255, 210, 255);
sf::Color foodColor(0, 0, 0, 255);
sf::Color snakeColor(0, 0, 0, 255);

sf::RectangleShape rec(sf::Vector2f(square, square));

sf::RectangleShape borders[4];

sf::Vector2f tilePos;
sf::RectangleShape mesh[amount][amount];

Food food(square, square);

sf::Text score;
auto scoreString = "Score: ";

sf::Font font;

sf::CircleShape cir(22);

sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

Snake snake;

int main(){

  font.loadFromFile("./include/arial.ttf");

  score.setString(scoreString + std::to_string(result));
  score.setCharacterSize(32);
  score.setFillColor(sf::Color::White);
  score.setPosition(textPosX, textPosY);
  score.setFont(font);

  genFood();
  makeMesh();
  makeBorders();
  rec.setPosition(120, 120);
  bool showCircle = false;
  food.setFillColor(sf::Color::Blue);
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
	  if(snake.getTowardX() != 10 && snake.getTowardY() != 0)
	    snake.setToward(-10, 0);
	  
	}else if(event.key.code == sf::Keyboard::D){
	  //rec.setPosition(tilePos.x + square, tilePos.y);
	  if(snake.getTowardX() != -10 && snake.getTowardY() != 0)
	    snake.setToward(10, 0);
	  
	}else if(event.key.code == sf::Keyboard::W){
	  //rec.setPosition(tilePos.x, tilePos.y - square);
	  if(snake.getTowardX() != 0 && snake.getTowardY() != 10)
	    snake.setToward(0, -10);
	  
	}else if(event.key.code == sf::Keyboard::S){
	  //rec.setPosition(tilePos.x, tilePos.y + square);
	  if(snake.getTowardX() != 0 && snake.getTowardY() != -10)
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
    //window.draw(rec);
    
    window.draw(score);
    drawBorders();
    window.draw(food);
    drawSnake(snake);
    
    if(contains(snake, rec)){
      ++result;
      score.setString(scoreString + std::to_string(result));
      snake.resizeBody();
      genFood();
    }
    
    
    if(snake.isCollision()){
      snake.body.at(0).setFillColor(sf::Color::Red);
      window.draw(snake.body.at(0));
      window.display();
      continue;
      //window.close();
    }

    //std::thread thread(drawSnake(rec));
    snake.setPosition();
    window.display();
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

      //if( row == amount && col == amount-1 ){
      //	mesh[row][col].setFillColor(sf::Color(255, 255, 255, 255));
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
  if(snake.getHeadX() == food.getX() && snake.getHeadY() == food.getY())
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

void makeBorders(){
  //static int w = width;
  borders[0].setSize(sf::Vector2f(width, square));
  borders[0].setPosition(0, dimension);
  borders[0].setFillColor(sf::Color::White);

  borders[1].setSize(sf::Vector2f(width, square));
  borders[1].setPosition(0, dimension + 90);
  borders[1].setFillColor(sf::Color::White);

  borders[2].setSize(sf::Vector2f(square, 100));
  borders[2].setPosition(0, dimension);
  borders[2].setFillColor(sf::Color::White);

  borders[3].setSize(sf::Vector2f(square, 100));
  borders[3].setPosition(dimension-10, dimension);
  borders[3].setFillColor(sf::Color::White);
}

void drawBorders(){
  window.draw(borders[0]);
  window.draw(borders[1]);
  window.draw(borders[2]);
  window.draw(borders[3]);
}

void drawCircle(bool show){
  if(show == true){
    window.draw(cir);
  }
  //  return ;
}
