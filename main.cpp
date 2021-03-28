#include<iostream>
#include "Ball.cpp"
using namespace std;

int main(int argc, char *argv[]){
  std::cout << "Number of arguments: " << argc;
  Ball ball(10, 10, 10);
  cout << ball.getX();
  return 0;
}
