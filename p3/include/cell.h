/**
 * PROJECT HEADER
 * @file cell.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */


#ifndef CELL_GAME_OF_LIFE_H
#define CELL_GAME_OF_LIFE_H

#include <iostream>
#include <cstdio>

#include "board.h"

class Board;
class Cell {
 protected:
  int rowInx_,colInx_;
  int aliveNeighbors_;

 public:
  Cell();
  Cell(int rowInx, int colInx);
  ~Cell();

  static Cell* createCell(int typeOfCell, int rowInx, int ColInx);

  virtual int getStatus(void) const; 
  virtual int updateStatus(void);    
  virtual int countNeighbors(Board& board);  
  virtual std::ostream& show(std::ostream& os) const;  

  int setStatus(int newStatus);
  int getAliveNeighbors(void);
};


#endif