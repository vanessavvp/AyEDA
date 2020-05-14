/**
 * PROJECT HEADER
 * @file arbolB.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#ifndef INCLUDE_ARBOLB_H
#define INCLUDE_ARBOLB_H

#include <deque>

#include "nodoB.hpp"

template <typename CLAVE>
class ArbolB {
 public:
  ArbolB()                    { raiz_ = nullptr; }
  ArbolB(NodoB<CLAVE>* raiz)  { raiz_ = raiz;    }
  ~ArbolB()                   { podar(raiz_);     }

  NodoB<CLAVE>* getRaiz(void);
  bool isVacio(NodoB<CLAVE>* nodo);
  bool isHoja(NodoB<CLAVE>* nodo);
  void podar(NodoB<CLAVE>* nodo);
  void recorreN(void);
  void procesar(NodoB<CLAVE>* nodo); //Funcion de impresion

  //Mod
  int tam(void)          { return tamRama(raiz_); }
  int tamRama(NodoB<CLAVE>*& nodo);
  bool equilibrado(void) { return equilibrioRama(raiz_); }
  const bool equilibrioRama(NodoB<CLAVE>*& nodo);

 protected:
  NodoB<CLAVE>* raiz_;
};



template <typename CLAVE>
NodoB<CLAVE>* ArbolB<CLAVE>::getRaiz(void) {
  return raiz_;
}



template <typename CLAVE>
bool ArbolB<CLAVE>::isVacio(NodoB<CLAVE>* nodo) {
  return nodo == nullptr;
}



template <typename CLAVE>
bool ArbolB<CLAVE>::isHoja(NodoB<CLAVE>* nodo) {
  return !nodo->derecho_ && !nodo->izquierdo_;
}



template <typename CLAVE>
void ArbolB<CLAVE>::podar(NodoB<CLAVE>* nodo) {
  if (nodo == nullptr)  return;//return

  podar(nodo->izquierdo_); //Podar subarbol izquierdo
  podar(nodo->derecho_); //Podar subarbol derecho

  delete nodo;
  nodo = nullptr;
}



template <typename CLAVE>
void ArbolB<CLAVE>::recorreN(void) {
  std::deque<std::pair<NodoB<CLAVE>*, int>> cola_auxiliar;
  NodoB<CLAVE>* nodo_auxiliar;
  int nivel, nivel_actual = 0;

  cola_auxiliar.push_back(std::pair<NodoB<CLAVE>*, int>(raiz_, 0));
  std::cout << "Nivel 0: ";

  while (!cola_auxiliar.empty()) {
    nodo_auxiliar = cola_auxiliar.front().first;
    nivel = cola_auxiliar.front().second;
    cola_auxiliar.pop_front();

    if (nivel > nivel_actual) {
      nivel_actual = nivel;
      std::cout << "\nNivel" << nivel_actual << ": ";
    }
    procesar(nodo_auxiliar);

    if (nodo_auxiliar != nullptr) {
      cola_auxiliar.push_back(std::pair<NodoB<CLAVE>*, int>(nodo_auxiliar->izquierdo_, nivel+1));
      cola_auxiliar.push_back(std::pair<NodoB<CLAVE>*, int>(nodo_auxiliar->derecho_, nivel+1));
    }
  }
}



template <typename CLAVE>
void ArbolB<CLAVE>::procesar(NodoB<CLAVE>* nodo) {
  if (nodo == nullptr)
    std::cout << "[.]";
                
  else
    std::cout << "[" << nodo->getDato() << "]";
}



template <typename CLAVE>
int ArbolB<CLAVE>::tamRama(NodoB<CLAVE>*& nodo) {
  if (nodo == nullptr) return 0;
  return (1 + tamRama(nodo->getIzquierdo()) + tamRama(nodo->getDerecho()));
}



template <typename CLAVE>
const bool ArbolB<CLAVE>::equilibrioRama(NodoB<CLAVE>*& nodo) {
  if (nodo == nullptr) return true;

  int nodo_equilibrado = (tamRama(nodo->getIzquierdo()) - tamRama(nodo->getDerecho()));

  switch (nodo_equilibrado) {

   case -1:  

    case 0:  

    case 1:  return equilibrioRama(nodo->getIzquierdo()) && equilibrioRama(nodo->getDerecho());

    default: return false;

  }
  
}


#endif //INCLUDE_ARBOLB_H