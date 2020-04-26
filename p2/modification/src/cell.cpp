/**
 * PROJECT HEADER
 * @file cell.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 10/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº2
 * Purpose: Game of life
 */

#include "../include/board.h"
#include "../include/cell.h"

Cell::Cell(void) {
  setStatus(0);
  rowInx_ = 0;
  colInx_ = 0;
}

Cell::Cell(int rowInx, int colInx) 
{
  rowInx_ = rowInx;
  colInx_ = colInx;
  setStatus(0);
}

Cell::~Cell(void) {
  status_ = 0;
  aliveNeighbors_ = 0;
}

int Cell::getStatus(void) const 
{
  return status_;
}

int Cell::setStatus(int newStatus) 
{
  status_ = newStatus;
  return status_;
}

int Cell::countNeighbors(Board& board) 
{
  aliveNeighbors_ = 0;
  for (int i = rowInx_-1; i <= rowInx_+1; i++) {
    for (int j = colInx_-1; j <= colInx_+1; j++) {
      if (board.isAliveCell(i,j)) {
        aliveNeighbors_++;
      }
    }
  }
  if (status_ == 1) {
      aliveNeighbors_ -=1;
  }
  return aliveNeighbors_;
} 


int Cell::updateStatus(void) 
{
  if(getStatus() == 0 && aliveNeighbors_ == 3) { //SI esta muerta y tiene 3 vecinas vivas, vive
    setStatus(1);
  }
  if (getStatus() == 1 && (aliveNeighbors_ == 2 || aliveNeighbors_ ==3)) { //Si esta viva y tiene 2 o 3 vecinas vivas, vive
    setStatus(1);                                                                        //por tanto si no se cumple, muere
  }
  else {
    setStatus(0);
  }
  return status_; //PROVISIONAL
}

int Cell::getNeighbors(void) 
{
  return aliveNeighbors_;
}

