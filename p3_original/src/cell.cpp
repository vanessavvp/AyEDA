/**
 * PROJECT HEADER
 * @file cell.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/board.h"
#include "../include/cell.h"
#include "../include/cell1.h"
#include "../include/cell2.h"
#include "../include/cell3.h"

Cell::Cell(int rowInx, int colInx) 
{
  rowInx_ = rowInx;
  colInx_ = colInx;
}



Cell::~Cell(void) {
  aliveNeighbors_ = 0;
}



int Cell::getStatus(void) const 
{
  return 0;
}



int Cell::countNeighbors(Board& board) 
{
  aliveNeighbors_ = 0;
  for (int i = rowInx_-1; i <= rowInx_+1; i++) {
    for (int j = colInx_-1; j <= colInx_+1; j++) {
      //Toda celula diferente de 0, será considerada viva
      if (board.getTable()[i * (board.getCol() + 2) + j]->getStatus() != 0) { 
        aliveNeighbors_++;
      }
    }
  }
  if (getStatus() != 0) {
    aliveNeighbors_-=1;
  }
  return aliveNeighbors_;
} 




int Cell::updateStatus(void)  //Reglas de nacimiento
{
  if (aliveNeighbors_ == 3) return 1;
  if (aliveNeighbors_ == 3 || aliveNeighbors_ == 6 || aliveNeighbors_ == 8) return 2;
  if (aliveNeighbors_ == 3 || aliveNeighbors_ == 4 || aliveNeighbors_ == 6) return 3;
  else return 0;
}



int Cell::getAliveNeighbors(void) 
{
  return aliveNeighbors_;
}



std::ostream& Cell::show(std::ostream& os) const
{
  os << " ";
  return os;
}



Cell* Cell::createCell(int typeOfCell, int rowInx, int colInx) 
{
  Cell* newCell;
  switch (typeOfCell) {
    case 0: 
      newCell = new Cell(rowInx, colInx); break;
    case 1:
      newCell = new Cell1(rowInx, colInx); break;
    case 2:
      newCell = new Cell2(rowInx, colInx); break;
    case 3:
      newCell = new Cell3(rowInx, colInx); break;
    default:
      std::cout << "Cell type not suported\n"; break;
  }
  return newCell;
}
