#include <iostream> 

#include "../include/board.h"
#include "../include/cell.h"
#include "../include/cell1.h"

int main (void) {
  Board board(10,10);

  int turn = 5;
  
  board.activarcelula(1,5,5);
  board.activarcelula(2,5,6);
  board.activarcelula(1,6,6);
  board.activarcelula(1,6,7);
  board.activarcelula(3,7,6);

  board.startGameofLife(turn);

  //std::cout << "Celula del tipo: " << cell.getStatus() << "\n";
  return EXIT_SUCCESS;
}