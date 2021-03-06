/**
 * PROJECT HEADER
 * @file cellx.h
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */


#ifndef CELLX_GAME_OF_LIFE_H
#define CELLX_GAME_OF_LIFE_H

#include "cell.h"

class Cellx : public Cell 
{
 public:
  Cellx(int rowInx, int colInx);
  int updateStatus(void); // Reglas de supervivencia
  int getStatus(void) const;
  std::ostream& show(std::ostream& os) const;
};
#endif
