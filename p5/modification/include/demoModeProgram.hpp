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
#include "../include/ISBN.hpp"


void initializeDemoMode() {
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

    srand(10);
    std::vector<ISBN> ISBN_vector(size);
    std::vector<ISBN> ISBN_result_vector(size);

    for (int i = 0; i < size; i++){
        ISBN_vector[i] = ISBN();
    }

    std::cout << "\n\t[I]nsertion\n\t[B]ubbleSort\n\t[H]eapSort\n\t[Q]uickSort";
    std::cout << "\n\t[S]hellSort\n\t-> ";
    std::cin >> sort_method;
    
    switch (sort_method) {
        case 'I':
          std::cout << "\n\t\t--- Insertion ---\nOriginal vector -> ";
          show(ISBN_vector);
          std::cout << "\nEvery modification will be shown on red\n";

          ISBN_result_vector = insertion<ISBN>(ISBN_vector, ISBN_vector.size(), 1);
          std::cout << "\nSorted vector -> ";
  
          for (int i = 0; i < ISBN_vector.size(); i++) {
            std::cout << ISBN_result_vector[i] << " ";
          }
          std::cout << "\n";
          break;
  

        case 'B':
          std::cout << "\n\t\t--- BubbleSort ---\nOriginal vector -> ";
          show(ISBN_vector);
          std::cout << "\nEvery modification will be shown on red\n";

          ISBN_result_vector = bubbleSort<ISBN>(ISBN_vector, ISBN_vector.size(), 1);
          std::cout << "\nSorted vector -> ";
          
  
          for (int i = 0; i < ISBN_vector.size(); i++) {
            std::cout << ISBN_result_vector[i] << " ";
          }
          std::cout << "\n";
          break;
  

        case 'H':
          std::cout << "\n\t\t--- HeapSort ---\nOriginal vector -> ";
          show(ISBN_vector);
          std::cout << "\nEvery modification will be shown on red\n";

          ISBN_result_vector = heapSort<ISBN>(ISBN_vector, ISBN_vector.size(), 1);
          std::cout << "\nSorted vector -> ";
          std::cout << "\nEvery modification will be shown on red\n";

  
          for (int i = 0; i < ISBN_vector.size(); i++) {
            std::cout << ISBN_result_vector[i] << " ";
          }
          std::cout << "\n";
          break;
  

        case 'Q':
          std::cout << "\n\t\t--- QuickSort ---\nOriginal vector -> ";
          show(ISBN_vector);
          std::cout << "\nEvery modification will be shown on red\n";

          ISBN_result_vector = quickSort<ISBN>(ISBN_vector, 0, ISBN_vector.size()-1, 1);
          std::cout << "\nSorted vector -> ";

  
          for (int i = 0; i < ISBN_vector.size(); i++) {
            std::cout << ISBN_result_vector[i] << " ";
          }
          std::cout << "\n";
          break;
  

        case 'S':
          std::cout << "\n\t\t--- ShellSort ---\n";
          std::cout << "Introduce the reduction factor between [0-1]: ";
          std::cin >> reduction_factor;
          while (reduction_factor <= 0 || reduction_factor >= 1){
            std::cout << "\nERROR: The reduction factor must be between [0-1]";
            std::cout << " please, introduce it again: ";
            std::cin >> reduction_factor;
          }

          std::cout << "Original vector -> ";
          show(ISBN_vector);
          std::cout << "\nEvery modification will be shown on red\n";

          ISBN_result_vector = shellSort<ISBN>(reduction_factor, ISBN_vector, ISBN_vector.size(), 1);
          std::cout << "\nSorted vector -> ";
  
          for (int i = 0; i < ISBN_vector.size(); i++) {
            std::cout << ISBN_result_vector[i] << " ";
          }
          std::cout << "\n";
          break;
      

        default:
          std::cout << "ERROR: The introduced option is not correct\n";
          break;
    }    
}







   