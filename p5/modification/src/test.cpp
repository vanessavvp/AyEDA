/**
 * PROJECT HEADER
 * @file test.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include "../include/sort.hpp"

#include <iostream>

int main(void) 
{
    std::cout << "\n------------- SORTING METHODS -------------\n";
    int value_ = 2;
    int tamam = 4;
    int method_number = 5;
    std::vector<int> vector {0, 3, 2, 5, 7, 1, 4};
    std::vector<int> vector_copy(vector.size());
    vector_copy = vector;
    float delta = 0.5;


    for (int selectedMethod = 0; selectedMethod < method_number; selectedMethod++) {
      switch (selectedMethod) {
        case 0:
          std::cout << "\nInsercion";
          vector_copy = insertion<int>(vector_copy, vector_copy.size(), 1);
          std::cout << "\nVector resultante: ";
          for (int i = 0; i < vector_copy.size(); i++) {
            std::cout << vector_copy[i] << " ";
          }
          std::cout << "\n";
          break;

        case 1:
          std::cout << "\nBubbleSort";
          vector_copy = bubbleSort<int>(vector_copy, vector_copy.size(), 1);
          std::cout << "\nVector resultante: ";
          for (int i = 0; i < vector_copy.size(); i++) {
            std::cout << vector_copy[i] << " ";
          }
          std::cout << "\n";
          break;

        case 2:
          std::cout << "\nHeapSort";
          vector_copy = heapSort<int>(vector_copy, vector_copy.size(), 1);
          std::cout << "\nVector resultante: ";
          for (int i = 0; i < vector_copy.size(); i++) {
            std::cout << vector_copy[i] << " ";
          }
          std::cout << "\n";
          break;

        case 3:
          std::cout << "\nQuickSort";
          vector_copy = quickSort<int>(vector_copy, 0, vector_copy.size()-1, 1);
          std::cout << "\nVector resultante: ";
          for (int i = 0; i < vector_copy.size(); i++) {
            std::cout << vector_copy[i] << " ";
          }
          std::cout << "\n";
          break;

        case 4:
          std::cout << "\nshellSort";
          vector_copy = shellSort<int>(delta, vector_copy, vector_copy.size(), 1);
          std::cout << "\nVector resultante: ";
          for (int i = 0; i < vector_copy.size(); i++) {
            std::cout << vector_copy[i] << " ";
          }
          std::cout << "\n";
          break;
  
        default:break;
      }
      vector_copy.clear();
      vector_copy.resize(vector.size());
      vector_copy = vector; 
    }
    return EXIT_SUCCESS;
}