#include<SFML/Graphics.hpp>

class Food : public sf::RectangleShape{
public:

  Food(int width, int height) : sf::RectangleShape(sf::Vector2f(width, height)){}
  
  int getX();
  int getY();
  void changePos(int x, int y);
};
