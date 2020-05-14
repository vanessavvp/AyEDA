/**
 * PROJECT HEADER
 * @file demoORstat.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#include <vector>

#include "../include/arbolBB.hpp"
#include "../include/DNI.hpp"


void ingresarClave(ArbolBB<DNI>& nuevo_arbol) { //Arbol<DNI>& nuevo_arbol) {
  int clave_dada; //int clave_dada
  DNI DNI_auxiliar; //

  std::cout << "\nInsertar: "; std::cin >> clave_dada;
  DNI_auxiliar.setIdNumber(clave_dada);
  nuevo_arbol.insertar(DNI_auxiliar);
  std::cout << "\n";
  nuevo_arbol.recorreN();
  std::cout << "\n";
}




void eliminarClave(ArbolBB<DNI>& nuevo_arbol) {
  int clave_dada; //DNI clave_dada
  DNI DNI_auxiliar;

  std::cout << "\nEliminar: "; std::cin >> clave_dada;
  DNI_auxiliar.setIdNumber(clave_dada);
  nuevo_arbol.eliminar(DNI_auxiliar); //nuevo_arbol.eliminar(DNI);
  std::cout << "\n";
  nuevo_arbol.recorreN();
  std::cout << "\n";
}


char modoDemostracion(void) {
  int clave_dada, opcion;
  ArbolBB<DNI> nuevo_arbol; //

  std::cout << "\nCreando el arbol vacío listo para ser utilizado...\n";
  std::cout << "\nArbol vacío\n";
  nuevo_arbol.recorreN();

  while (opcion != 0) {
    std::cout << "\nBienvenido al modo demostración! Por favor, escoge la opción que desee a continuación: \n";
    std::cout << "\t[0] Salir\n";
    std::cout << "\t[1] Insertar Clave\n";
    std::cout << "\t[2] Eliminar Clave\n";
    std::cout << "\t[3] Verificar si está PERFECTAMENTE equilibrado el árbol\n";
    std::cout << "\tOpción: ";
    std::cin >> opcion;

    switch (opcion) {

      case 1:  ingresarClave(nuevo_arbol); break;

      case 2:  eliminarClave(nuevo_arbol); break;

      //Modificacion
      case 3: 
        nuevo_arbol.recorreN(); 
        if (nuevo_arbol.equilibrado()) std::cout << "\nEl árbol está PERFECTAMENTE equilibrado\n";
        else std::cout << "\nEl árbol no está PERFECTAMENTE equilibrado\n"; break;

      case 0:  std::cout << "\n¡Hasta luego!\n"; break;

      default: std::cout << "\nERROR: Ha introducido la opción incorrecta\n"; break;

    }
  } 

  return 'R';
}



char modoEstadistica(void) {
  int tam_arbol, n_pruebas; //tam_arbol = N EN EL PDF
  char opcion_salida;
  
  while (opcion_salida != 'N') {
    std::cout << "\nTamaño del árbol: ";  std::cin >> tam_arbol;
    std::cout << "Número de pruebas: "; std::cin >> n_pruebas;
  
    int tam_banco_pruebas = tam_arbol * 2;

    srand(1000); //srand(time(NULL))
    std::vector<DNI> banco_pruebas(tam_banco_pruebas);
    //std::cout << "DNI creados: "; //Para imprimir los DNI creados si se queire verificar
    //for (int i = 0; i < tam_banco_pruebas; i++) {
    //  std::cout << banco_pruebas[i] << " ";
    //}

    ArbolBB<DNI> nuevo_arbol;
    DNI::counter.reset();
  
    for (int j = 0; j < tam_arbol; j++) 
      nuevo_arbol.insertar(banco_pruebas[j]);
  
    std::cout << "\n\n\t\tNÚMERO DE COMPARACIONES\n";
    std::cout << std::setw(18) << "N" << std::setw(16) << "Pruebas";
    std::cout << std::setw(10) << "Mínimo" << std::setw(9) << "Medio";
    std::cout << std::setw(13) << "Máximo\n";
    
    // Experimento de busqueda
    for (int prueba_actual = 0; prueba_actual < n_pruebas; prueba_actual++) {
      DNI::counter.resetQuantity();
      nuevo_arbol.buscar(banco_pruebas[rand() % tam_arbol]);
      DNI::counter.calculateStatistics();
    }
    std::cout << std::setw(10) << "Búsqueda"; 
    DNI::counter.showStatisticsResults(tam_arbol, n_pruebas);
    DNI::counter.reset();
  
    // Experimento de insercion
    for (int prueba_actual = 0;  prueba_actual < n_pruebas; prueba_actual++) {
      DNI::counter.resetQuantity();
      nuevo_arbol.buscar(banco_pruebas[(rand() % tam_arbol) + tam_arbol]);
      //nuevo_arbol.buscar(banco_pruebas[rand() % (tam_arbol - (tam_arbol * 2 - 1))]);
      DNI::counter.calculateStatistics();
    }
  
    std::cout << std::setw(9) << "Inserción";
    DNI::counter.showStatisticsResults(tam_arbol, n_pruebas);
    DNI::counter.reset();
  
  
    // Opcion de salida
    std::cout << "\n¿Desea intentarlo de nuevo? [S - N] \n"; std::cin >> opcion_salida;

  } 
  std::cout << "\n¡Hasta luego!\n";
 
  return 'R';
  
  
}