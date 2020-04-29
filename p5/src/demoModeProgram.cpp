/**
 * PROJECT HEADER
 * @file demoModeProgram.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include <iostream>

#include "../include/sort.hpp"
#include "../include/DNI.hpp"

void userInteraction();
int main (void) {
    std::cout << "\n\t\tSorting methods\n\n\t--- Demonstration Mode Program ---\n";  
    userInteraction();
    std::cout << "\nEnding demonstration...";
  
    return EXIT_SUCCESS;
}



void userInteraction() {
    int size;
    float reduction_factor;
    char sort_method;

    std::cout << "Introduce the following information below: \n";
    std::cout << "Vector size between [1-25]: ";
    std::cin >> size;
    while (size < 1 || size > 25){
        std::cout << "\nERROR: The vector size must be between [1-25], please";
        std::cout << "enter again the information: ";
        std::cin >> size;
    }

    srand(time(NULL));
    std::vector<DNI> DNI_vector(size);
    std::vector<DNI> DNI_result_vector(size);

    for (int i = 0; i < size; i++){
        DNI_vector[i] = DNI();
    }

    std::cout << "\n\t[I]nsertion\n\t[B]ubbleSort\n\t[H]eapSort\n\t[Q]uickSort";
    std::cout << "\n\t[S]hellSort\n\t-> ";
    std::cin >> sort_method;
    
    switch (sort_method) {
      case 'I':
        std::cout << "\n\t\tInsertion\n";
        //Llamar a la funcion de imprimir traza
        DNI_result_vector = insertion<DNI>(DNI_vector, DNI_vector.size());
        std::cout << "\nSorted vector: ";

        for (int i = 0; i < DNI_vector.size(); i++) {
          std::cout << DNI_result_vector[i] << " ";
        }
        std::cout << "\n";
        break;

      case 'B':
        std::cout << "\n\t\tBubbleSort\n";
        //Llamar a la funcion de imprimir traza
        DNI_result_vector = bubbleSort<DNI>(DNI_vector, DNI_vector.size());
        std::cout << "\nSorted vector: ";

        for (int i = 0; i < DNI_vector.size(); i++) {
          std::cout << DNI_result_vector[i] << " ";
        }
        std::cout << "\n";
        break;

      case 'H':
        std::cout << "\n\t\tHeapSort\n";
        //Llamar a la funcion de imprimir traza
        DNI_result_vector = heapSort<DNI>(DNI_vector, DNI_vector.size());
        std::cout << "\nSorted vector: ";

        for (int i = 0; i < DNI_vector.size(); i++) {
          std::cout << DNI_result_vector[i] << " ";
        }
        std::cout << "\n";
        break;

      case 'Q':
        std::cout << "\n\t\tQuickSort\n";
        //Llamar a la funcion de imprimir traza
        DNI_result_vector = quickSort<DNI>(DNI_vector, 0, DNI_vector.size()-1);
        std::cout << "\nSorted vector: ";

        for (int i = 0; i < DNI_vector.size(); i++) {
          std::cout << DNI_result_vector[i] << " ";
        }
        std::cout << "\n";
        break;

      case 'S':
        std::cout << "\n\t\tShellSort\n";
        std::cout << "Introduce the reduction factor between [0-1]: ";
        std::cin >> reduction_factor;

        while (reduction_factor <= 0 || reduction_factor >= 1){
          std::cout << "\nERROR: The reduction factor must be between [0-1]";
          std::cout << " please, introduce it again: ";
          std::cin >> reduction_factor;
        }
        //Llamar a la funcion de imprimir traza
        DNI_result_vector = quickSort<DNI>(DNI_vector, 0, DNI_vector.size()-1);
        std::cout << "\nSorted vector: ";

        for (int i = 0; i < DNI_vector.size(); i++) {
          std::cout << DNI_result_vector[i] << " ";
        }
        std::cout << "\n";
        break;
    
      default:
        std::cout << "ERROR: The introduce option is not correct\n";
        break;
    }    
}







   