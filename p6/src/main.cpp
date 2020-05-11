/**
 * PROJECT HEADER
 * @file main.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#include "../include/arbolBB.hpp"

int main(void) {
  char opcion;
  int dato = 2;
  NodoB<int>* nodo;
  nodo->setDato(dato);
  ArbolBB<int> tree(nodo);

  std::cout << "\n--- ÁRBOLES BINARIOS DE BÚSQUEDA ---\n";
  std::cout << "Selecciona el modo del programa: \n";
  std::cout << "\t[D]emostración\n";
  std::cout << "\t[E]xperimento\n";
  std::cout << "\t[S]alir\n";
  std::cout << "\tOpción: ";
  std::cin >> opcion;

  do {
    switch (opcion) {
      case 'D':
        tree.procesar(nodo);
        break;
  

      case 'E':
        break;
  

      case 'S':
        break;
      

      default:
        std::cout << "ERROR: La opción introducida no es correcta...\n";
        break;
    }
  } while (opcion != 'S');

  return EXIT_SUCCESS;
}