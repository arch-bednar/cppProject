#include<iostream>
#include "Ball.h"
#include "Board.h"
#include "Tile.h"

using namespace std;

int main(int argc, char *argv[]){
  Shape *sh;
  Shape s(3,4);
  Rectangle r(1,2,5,5);
  Board b(5,6,5,5);
  Ball ba(12,1,6);
  Tile t(2,2);
  
  Shape tab[5] = {s,r,b,ba,t};

  for (int i=0; i<5; i++){
    cout << tab[i].getX();
  }
}
