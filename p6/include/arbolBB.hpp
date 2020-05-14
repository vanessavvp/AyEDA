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
  ArbolBB() : ArbolB<CLAVE>() {};
  ArbolBB(NodoB<CLAVE>* raiz) : ArbolB<CLAVE>(raiz) {};

  NodoB<CLAVE>* buscar(CLAVE& clave_dada);
  NodoB<CLAVE>* buscarRama(NodoB<CLAVE>*& nodo, CLAVE& clave_dada);

  void insertar(CLAVE& clave_dada);
  void insertarRama(NodoB<CLAVE>*& nodo_raiz, CLAVE& clave_dada);
  void eliminar(CLAVE& clave_dada);
  void eliminarRama(NodoB<CLAVE>*& nodo_raiz, CLAVE& clave_dada);
  void sustituye(NodoB<CLAVE>*& nodo_eliminado, NodoB<CLAVE>*& nodo_sustituto);

 private:
};



template <typename CLAVE>
NodoB<CLAVE>* ArbolBB<CLAVE>::buscar(CLAVE& clave_dada) {
  return buscarRama(this->raiz_, clave_dada); //raiz
}



template <typename CLAVE>
NodoB<CLAVE>* ArbolBB<CLAVE>::buscarRama(NodoB<CLAVE>*& nodo, CLAVE& clave_dada) {

  if (nodo == nullptr)
    return nullptr;

  CLAVE clave_auxiliar = nodo->getDato();

  if (clave_dada == clave_auxiliar)
    return nodo;

  if (clave_dada < clave_auxiliar)
    return buscarRama(nodo->getIzquierdo(), clave_dada);

  return buscarRama(nodo->getDerecho(), clave_dada);
}



template <typename CLAVE>
void ArbolBB<CLAVE>::insertar(CLAVE& clave_dada) {
  insertarRama(this->raiz_, clave_dada); //raiz_
}



template <typename CLAVE>
void ArbolBB<CLAVE>::insertarRama(NodoB<CLAVE>*& nodo_raiz, CLAVE& clave_dada) {
  if (nodo_raiz == nullptr)
    nodo_raiz = new NodoB<CLAVE>(clave_dada);

  else if (clave_dada < nodo_raiz->getDato())
    insertarRama(nodo_raiz->getIzquierdo(), clave_dada);

  else 
    insertarRama(nodo_raiz->getDerecho(), clave_dada);

  //if (nodo_raiz == nullptr)
  //  std::cout << "nodo";
}



template <typename CLAVE>
void ArbolBB<CLAVE>::eliminar(CLAVE& clave_dada) {
  eliminarRama(this->raiz_, clave_dada); //raiz_
}



template <typename CLAVE>
void ArbolBB<CLAVE>::eliminarRama(NodoB<CLAVE>*& nodo_raiz, CLAVE& clave_dada) {
  if (nodo_raiz == nullptr)
    std::cout << "\nHa escogido un nodo que no existe en el árbol actualmente...\n";

  else {

    if (clave_dada < nodo_raiz->getDato())
      eliminarRama(nodo_raiz->getIzquierdo(), clave_dada);

    else if (clave_dada > nodo_raiz->getDato())
      eliminarRama(nodo_raiz->getDerecho(), clave_dada);

    else {
      NodoB<CLAVE>* nodo_eliminado = nodo_raiz;

      if (nodo_raiz->getDerecho() == nullptr)
        nodo_raiz = nodo_raiz->getIzquierdo();

      else if (nodo_raiz->getIzquierdo() == nullptr)
        nodo_raiz = nodo_raiz->getDerecho();

      else 
        sustituye(nodo_eliminado, nodo_raiz->getIzquierdo());

      delete nodo_eliminado;
      nodo_eliminado = nullptr;
    }
  }
}



template <typename CLAVE>
void ArbolBB<CLAVE>::sustituye(NodoB<CLAVE>*& nodo_eliminado, NodoB<CLAVE>*& nodo_sustituto) {
  if (nodo_sustituto->getDerecho() != nullptr)
    sustituye(nodo_eliminado, nodo_sustituto->getDerecho());

  else {
    CLAVE copia_nodo_sustituto = nodo_sustituto->getDato();
    nodo_eliminado->setDato(copia_nodo_sustituto);
    nodo_eliminado = nodo_sustituto;
    nodo_sustituto = nodo_sustituto->getIzquierdo();
  }
}


#endif //INCLUDE_ARBOLBB_H