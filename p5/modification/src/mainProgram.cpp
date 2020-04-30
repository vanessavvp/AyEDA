/**
 * PROJECT HEADER
 * @file mainProgram.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include "../include/statModeProgram.hpp"
#include "../include/demoModeProgram.hpp"

int main (void) {
    char option, restart_option;

    std::cout << "\n--- SORTING METHODS ---\n";
    std::cout << "Choose one of the option above: \n";
    std::cout << "\t[D]emonstration Mode\n";
    std::cout << "\t[S]tatistics Mode\n";
    std::cout << "\t[Q]uit\n";
    std::cout << "\tOption: ";
    std::cin >> option;

    do {
        switch (option) {
        case 'D':
          initializeDemoMode();
          break;
  

        case 'S':
          initializeStatMode();
          break;
  

        case 'Q':
          break;
      

        default:
          std::cout << "ERROR: The introduced option is not correct...\n";
          break;
        }
    } while (option != 'Q');
    


    return EXIT_SUCCESS;
}