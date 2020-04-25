/**
 * PROJECT HEADER
 * @file cellX.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/cellx.h"

Cellx::Cellx(int rowInx, int colInx) : Cell(rowInx, colInx) {}

int Cellx::updateStatus(void) 
{
  if (aliveNeighbors_ == 1) return 4; //Le añadimos el numero 4, para representar la celula x 
                                       //Ya que el método tiene que retornar un int
  else return 0;
} // Reglas de supervivencia

int Cellx::getStatus(void) const
{
  return 4;
}

std::ostream& Cellx::show(std::ostream& os) const 
{
  os << "x";
  return os;
}
