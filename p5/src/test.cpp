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
    int tamam {4};
    std::vector<int> vector {0, 3, 2, 5, 7, 1, 4};
    std::vector<int> resultVector;

    std::cout << "\nInsercion";
    resultVector = insertion<int>(vector, vector.size());
    std::cout << "\nVector resultante: ";
    for (int i = 0; i < resultVector.size(); i++) {
      std::cout << resultVector[i] << " ";
    }
    std::cout << "\n";

    resultVector.clear();
    std::cout << "\nBubbleSort";
    vector = {0, 3, 2, 5, 7, 1, 4};
    resultVector = bubbleSort<int>(vector, vector.size());
    std::cout << "\nVector resultante: ";
    for (int i = 0; i < resultVector.size(); i++) {
      std::cout << resultVector[i] << " ";
    }
    std::cout << "\n";

    resultVector.clear();
    std::cout << "\nHeapSort";
    vector = {0, 3, 2, 5, 7, 1, 4};
    resultVector = heapSort<int>(vector, vector.size());
    std::cout << "\nVector resultante: ";
    for (int i = 0; i < resultVector.size(); i++) {
      std::cout << resultVector[i] << " ";
    }
    std::cout << "\n";
    

    resultVector.clear();
    std::cout << "\nQuickSort";
    vector = {0, 3, 2, 5, 7, 1, 4};
    resultVector = quickSort<int>(vector, 0, vector.size()-1);
    std::cout << "\nVector resultante: ";
    for (int i = 0; i < resultVector.size(); i++) {
      std::cout << resultVector[i] << " ";
    }
    std::cout << "\n";

    resultVector.clear();
    std::cout << "\nshellSort";
    vector = {0, 3, 2, 5, 7, 1, 4};
    float alfa = 0.5;
    resultVector = shellSort<int>(alfa, vector, vector.size());
    std::cout << "\nVector resultante: ";
    for (int i = 0; i < resultVector.size(); i++) {
      std::cout << resultVector[i] << " ";
    }
    std::cout << "\n";

    return 0;
}