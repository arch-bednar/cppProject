#include<SFML/Graphics.hpp>

class Food : public sf::RectangleShape{
public:

  Food(int width, int height) : sf::RectangleShape(sf::Vector2f(width, height)){
    this->setFillColor(sf::Color::Blue);
  }

  ~Food();
  
  int getX();
  int getY();
  bool isEaten(int x, int y);
  void changePos(int x, int y);
};
