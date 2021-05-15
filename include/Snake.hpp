#include<stdbool.h>
#include<vector>
#include<SFML/Graphics.hpp>

class Snake{

public:
  
  std::vector <sf::RectangleShape> body;
  bool isDead = false;

  //constructor
  Snake();

  //destructor
  ~Snake();
  
  //getMethods
  int getHeadX();
  int getHeadY();
  int getLastX();
  int getLastY();
  int getTowardX();
  int getTowardY();

  //setMethods
  void setToward(int x, int y);
  void setPosition();
  void setDeadHead();
  
  //resizeBody method
  void resizeBody();

  //checkingMethods
  bool isCollision();
  
  //drawing methods
  void draw(sf::RenderWindow &window);
  

private:
  
  int toward[2] = {0,10};
  
};
