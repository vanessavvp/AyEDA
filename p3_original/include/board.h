/**
 * PROJECT HEADER
 * @file board.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
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
  Cell** getTable(void);
  Cell* getCell(int rowInx, int colInx);

  void setRow(int row);
  void setCol(int col);

  int pos(int i, int j);
  
  void startGameofLife(int& numberOfTurns);
  void printBoard(int numberOfTurns);
  void constructionBoard(void);
  void initializeCoordinates(int& initialAliveCells);
  void activarcelula(int type, int rowInx, int colInx);

  bool isAliveCell(int rowInx, int colInx);
  bool isOutOfRange(int rowInx, int colInx);

  Cell* operator[](int position);
};

#endif