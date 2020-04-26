/**
 * PROJECT HEADER
 * @file cell.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 10/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº2
 * Purpose: Game of life
 */


#ifndef CELL_GAME_OF_LIFE_H
#define CELL_GAME_OF_LIFE_H

#include <iostream>
#include <cstdio>

#include "board.h"

class Board;
class Cell {
 private:
  int status_;
  int rowInx_,colInx_;
  int aliveNeighbors_;

 public:
  Cell(void);
  Cell(int rowInx, int colInx);
  ~Cell();
  int getStatus(void) const;
  int setStatus(int newStatus);
  int updateStatus(void);
  int countNeighbors(Board& board);
  int getNeighbors(void);
};

#endif