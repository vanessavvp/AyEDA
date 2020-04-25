/**
 * PROJECT HEADER
 * @file cell2.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/cell2.h"

Cell2::Cell2(int rowInx, int colInx) : Cell(rowInx, colInx) {}

int Cell2::updateStatus(void) 
{
  if (getAliveNeighbors() == 2 || getAliveNeighbors() == 4 || getAliveNeighbors() == 5) return 2;
  else return 0;
} // Reglas de supervivencia

int Cell2::getStatus(void) const
{
  return 2;
}

std::ostream& Cell2::show(std::ostream& os) const 
{
  os << "2";
  return os;
}
