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
  std::cout << "\t[S]alir\n";
  std::cout << "\tOpción: ";
  std::cin >> opcion;

  while (opcion != 'S') {

    switch (opcion) {

      case 'D': opcion = modoDemostracion(); break;
  

      case 'E': opcion = modoEstadistica();  break;


      case 'S': std::cout << "\n¡Hasta luego!\n"; break;


      case 'R':  return EXIT_SUCCESS;  //Salir desde modo demostracion o estadistica
      

      default: std::cout << "ERROR: La opción introducida no es correcta...\n"; return EXIT_FAILURE;

    }

  } 
  return EXIT_SUCCESS;
}