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

#include "DNI.hpp"
#include "sort.hpp"


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
    std::vector<std::vector<DNI>> test_bench(test_number);
    std::vector<std::string> method_name {"Insertion", "BubbleSort", "HeapSort", "QuickSort", "ShellSort"};

    for (int i = 0; i < test_bench.size(); i++) {
      std::vector<DNI> sequence(vector_size);
      test_bench[i] = sequence;
    }    

    std::vector<std::vector<DNI>> test_bench_copy(test_number);
    test_bench_copy = test_bench;
    std::cout <<"\n\t\tMinimum\t      Mean\t    Maximum\n";

    for (int selectedMethod = 0; selectedMethod < methodsNumber; selectedMethod++) {
      for (int j = 0; j < test_number; j++) {
        DNI::counter.resetQuantity();
        switch (selectedMethod) {
        case 0:
          insertion<DNI>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;

        case 1:
          bubbleSort<DNI>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;
    
        case 2:
          heapSort<DNI>(test_bench_copy[j], test_bench_copy[j].size(), 0); break;

        case 3:
          quickSort<DNI>(test_bench_copy[j], 0, test_bench_copy[j].size()-1, 0); break;

        case 4:
          shellSort<DNI>(delta, test_bench_copy[j], test_bench_copy[j].size(), 0); break;
  
        default:break;
        }
        DNI::counter.calculateStatistics();
      }
      DNI::counter.showStatisticsResults(method_name.at(selectedMethod));
      DNI::counter.reset();

      test_bench_copy =  test_bench;
    }
}
