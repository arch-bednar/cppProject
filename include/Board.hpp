#include<SFML/Graphics.hpp>

class Board{

public:
  Board();
  ~Board();
  
  void fillRed(int x, int y);
  void draw(sf::RenderWindow &window);
  
private:
  static const int dimension = 800;
  static const int amount = 80;
  static const int square = dimension/amount;
  sf::RectangleShape mesh[amount][amount];
  
  void makeMesh();
};
