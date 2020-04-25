/**
 * PROJECT HEADER
 * @file cell1.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/cell1.h"

Cell1::Cell1(int rowInx, int colInx) : Cell(rowInx, colInx) {}



int Cell1::updateStatus(void) 
{
  if (aliveNeighbors_ == 2 || aliveNeighbors_ == 3) return 1;
  else return 0;
} // Reglas de supervivencia



int Cell1::getStatus(void) const
{
  return 1;
}



std::ostream& Cell1::show(std::ostream& os) const 
{
  os << "1";
  return os;
}
