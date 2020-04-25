/**
 * PROJECT HEADER
 * @file cell3.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/cell3.h"

Cell3::Cell3(int rowInx, int colInx) : Cell(rowInx, colInx) {}

int Cell3::updateStatus(void) 
{
  if (getAliveNeighbors() == 5 || getAliveNeighbors() == 1) return 3;
  else return 0;
} // Reglas de supervivencia



int Cell3::getStatus(void) const
{
  return 3;
}



std::ostream& Cell3::show(std::ostream& os) const 
{
  os << "3";
  return os;
}
