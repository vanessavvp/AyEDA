/**
 * PROJECT HEADER
 * @file optionsMain.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#include "demoORstat.cpp"

int main(void) {
  char opcion;
  char opcion_auxiliar;

  std::cout << "\n--- ÁRBOLES BINARIOS DE BÚSQUEDA ---\n";
  std::cout << "Selecciona el modo del programa: \n";
  std::cout << "\t[D]emostración\n";
  std::cout << "\t[E]xperimento\n";
  std::cout << "\tOpción: ";
  std::cin >> opcion;

  do {
    switch (opcion) {


      case 'D': 
        opcion_auxiliar = modoDemostracion(); 
        opcion = opcion_auxiliar;
        break;
  

      case 'E': 
        opcion_auxiliar = modoEstadistica();  
        opcion = opcion_auxiliar;
        break;
      

      default: std::cout << "ERROR: La opción introducida no es correcta...\n"; break;


    }

  } while (opcion != 'S');

  return EXIT_SUCCESS;
}