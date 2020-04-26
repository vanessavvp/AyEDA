/**
 * PROJECT HEADER
 * @file board.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 10/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº2
 * Purpose: Game of life
 */


#ifndef BOARD_GAME_OF_LIFE_H
#define BOARD_GAME_OF_LIFE_H

#include <iostream>
#include <cstdio>
#include <chrono>
#include <thread>

#include "cell.h"

class Cell;
class Board {
 private:
  Cell** table_;
  int row_,col_;

 public:
  Board() {};
  Board(int row, int col);
  ~Board();
  int getRow(void);
  int getCol(void);
  void setRow(int row);
  void setCol(int col);
  int pos(int i, int j);
  Cell* operator[](int position);
  void startGameofLife(int& numberOfTurns);
  Cell* wantedPosition(int rowInx, int colInx);
  bool isAliveCell(int rowInx, int colInx);
  void printBoard(int numberOfTurns);
  void constructionBoard(void);
  void initializeCoordinates(int& initialAliveCells);
  bool isOutOfRange(int rowInx, int colInx);
};

#endif
