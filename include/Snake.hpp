#include<stdbool.h>
#include<vector>
#include<SFML/Graphics.hpp>
class Snake{
public:
  int toward[2] = {0,10};

  bool isDead = false;
  std::vector <sf::RectangleShape> body;

  //constructor
  Snake();
  
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

  //resizeBody method
  void resizeBody();

  //checkingMethods
  bool isCollision();
  
};
