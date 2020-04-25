/**
 * PROJECT HEADER
 * @file cell1.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */


#ifndef CELL1_GAME_OF_LIFE_H
#define CELL1_GAME_OF_LIFE_H

#include "cell.h"

class Cell1 : public Cell 
{

 public:
  Cell1(int rowInx, int colInx);
  int updateStatus(void); // Reglas de supervivencia
  int getStatus(void) const;
  std::ostream& show(std::ostream& os) const;
};
#endif