#include<SFML/Graphics.hpp>
#include<string>

class Score{

public:

  int countOfBorders=4;
  
  std::string scoreString = "Score: ";

  int result = 0;

  Score(int dimension, int square);
  ~Score();

  //set methods
  void setScore();

  //draw methods
  void draw(sf::RenderWindow &window);

private:

  int dimension;
  int square;
  
  const int textPosY = 830;
  const int textPosX = 350;

  sf::RectangleShape borders[4];
  sf::Text myScore;
  sf::Font font;
  
  void makeFont();
  void makeBorders();
  
  void drawScore(sf::RenderWindow &window);
  void drawBorders(sf::RenderWindow &window);
};
