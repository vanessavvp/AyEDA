/**
 * PROJECT HEADER
 * @file nodoB.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#ifndef INCLUDE_NODOB_H
#define INCLUDE_NODOB_H

#include <iostream>

template <typename CLAVE>
class NodoB {
 public:
  NodoB();
  NodoB(int dato, NodoB<CLAVE>* izquierdo = nullptr, NodoB<CLAVE>* derecho = nullptr);
  ~NodoB(){};

  CLAVE getDato(void)               { return dato_;     }
  NodoB<CLAVE>*& getIzquierdo(void) { return izquierdo_;}
  NodoB<CLAVE>*& getDerecho(void)   { return derecho_;  }

  void setDato(CLAVE dato)                        { dato_      = dato;           }
  void setIzquierdo(NodoB<CLAVE>* nuevoIzquierdo) { izquierdo_ = nuevoIzquierdo; }
  void setDerecho(NodoB<CLAVE>* nuevoDerecho)     { derecho_   = nuevoDerecho;   }
  void write();

 public:
  CLAVE dato_;
  NodoB<CLAVE>* izquierdo_;
  NodoB<CLAVE>* derecho_;
};



template <typename CLAVE>
NodoB<CLAVE>::NodoB(void) {
  izquierdo_ = nullptr;
  derecho_   = nullptr;
}



template <typename CLAVE>
NodoB<CLAVE>::NodoB(int dato, NodoB<CLAVE>* izquierdo, NodoB<CLAVE>* derecho) {
  dato_      = dato;
  izquierdo_ = izquierdo;
  derecho_   = derecho;
}



template <typename CLAVE>
void NodoB<CLAVE>::write(void) {
  if (this == NULL)
    std::cout << "[.]";

  else
    std::cout << "[" << dato_ << "]";
}

#endif //INCLUDE_NODOB_H