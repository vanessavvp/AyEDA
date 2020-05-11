/**
 * PROJECT HEADER
 * @file arbolBB.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#ifndef INCLUDE_ARBOLBB_H
#define INCLUDE_ARBOLBB_H

#include "arbolB.hpp"

template <typename CLAVE>
class ArbolBB : public ArbolB<CLAVE>{
 public:
  ArbolBB(NodoB<CLAVE>* raiz) : ArbolB<CLAVE>(raiz) {};
 private:
};

#endif