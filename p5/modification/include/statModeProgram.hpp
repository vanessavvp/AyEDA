/**
 * PROJECT HEADER
 * @file statModeProgram.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include <iostream>
#include <vector>

#include "../include/ISBN.hpp"
#include "../include/sort.hpp"


void initializeStatMode(void) {
    int vector_size;
    int test_number;
    int methodsNumber = 5;
    float delta;

    std::cout << "Vector size: ";
    std::cin >> vector_size;
    std::cout << "Test number: ";
    std::cin >> test_number;
    std::cout << "Delta [0-1]: ";
    std::cin >> delta; 

    srand(10);
    std::vector<std::vector<ISBN>> test_bench(test_number);
    std::vector<std::string> method_name {"Insertion", "BubbleSort", "HeapSort", "QuickSort", "ShellSort"};

    for (int i = 0; i < test_bench.size(); i++) {
      std::vector<ISBN> sequence(vector_size);
      test_bench[i] = sequence;
    }    

    std::vector<std::vector<ISBN>> test_bench_copy(test_number);
    test_bench_copy = test_bench;
    
    std::cout <<"\n\t\tMinimum\t      Mean\t    Maximum\n";

    for (int selectedMethod = 0; selectedMethod < methodsNumber; selectedMethod++) {
      for (int j = 0; j < test_number; j++) {
        ISBN::counter.resetQuantity();
        switch (selectedMethod) {
        case 0:
          insertion<ISBN>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;

        case 1:
          bubbleSort<ISBN>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;
    
        case 2:
          heapSort<ISBN>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;

        case 3:
          quickSort<ISBN>(test_bench_copy[j], 0, test_bench_copy[j].size()-1, 0); break;

        case 4:
          shellSort<ISBN>(delta, test_bench_copy[j], test_bench_copy[j].size(), 0); break;
  
        default:break;
        }
        ISBN::counter.calculateStatistics();
      }
      ISBN::counter.showStatisticsResults(method_name.at(selectedMethod));
      ISBN::counter.reset();

      test_bench_copy =  test_bench;
    }
}
