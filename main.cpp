#include<iostream>
#include "Ball.cpp"
//#include "Board.cpp"

using namespace std;

int main(int argc, char *argv[]){
  std::cout << "Number of arguments: " << argc;
  Ball ball(10, 10, 10);
  cout << ball.getX()<<endl;

  //Board board(10, 10, 20, 20);
  //cout <<board.getX();
  return 0;
}
