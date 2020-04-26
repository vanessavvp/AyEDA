/**
 * PROJECT HEADER
 * @file game_of_life.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 10/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº2
 * Purpose: Game of life
 */

#include <iostream> 

#include "../include/board.h"
#include "../include/cell.h"

void userInteraction(void);
int main (int argc, char *argv[]) {
  
  std::cout << "------------------------------------------------------------------------------\n";
  std::cout << "\n\tWelcome to the 'Game of Life'\n";
  
  userInteraction();

  return EXIT_SUCCESS;
}



void userInteraction(void) 
{
  int numberOfRows, numberOfCols;
  int maximumTurns, initialAliveCells;
  char restartOption;

  std::cout << "Please enter some information of the board\n";
  std::cout << "Number of rows: ";
  std::cin >> numberOfRows;
  std::cout << "Number of columns: ";
  std::cin >> numberOfCols;
  std::cout << "Maximum number of turns: ";
  std::cin >> maximumTurns;
  
  Board board(numberOfRows, numberOfCols); 

  std::cin.clear();
  std::cout << "\n*Initial values* \n";
  std::cout << "Number of alive cells: ";
  std::cin >> initialAliveCells;
 
  board.initializeCoordinates(initialAliveCells);
  board.startGameofLife(maximumTurns);
  
  std::cout << "\nDo you want to restart the game? [y/n] ";
  std::cin >> restartOption;
  switch (restartOption)
  {
  case 'y':
    userInteraction();
    break;
  
  default:
    std::cout << "See you later!\n";
    break;
  }
}

