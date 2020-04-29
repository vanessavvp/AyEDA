/**
 * PROJECT HEADER
 * @file sort.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include "../include/DNI.hpp"
#include <vector>
#include <iostream>


template <typename Clave> 
void show(std::vector<Clave>& sequence) {  
  for (int i = 0; i < sequence.size(); i++) 
    std::cout << sequence[i] << " ";
  std::cout << "\n";
}


//---------------- Quadratic Sorting Methods ------------------------

template <typename Clave> 
std::vector<Clave> insertion(std::vector<Clave>& sequence, int size, int mode) {
  int j;
  Clave new_element_x;
  int aux, aux2;
  std::string red_color = "31m";

  for (int i = 1; i < size; i++) {
    j = i;
    new_element_x = sequence[i];
    
    while (new_element_x < sequence[j-1]) {
      sequence[j] = sequence[j-1];
      aux = j;
      j--;
    }
    sequence[j] = new_element_x;
    aux2 = j;

    //Demonstration Mode = 1 ------------------------------------------------------
    if (mode == 1) {
      std::cout << "\nEvery modification will be shown on red\n";
      for (int i = 0; i < sequence.size(); i++) {
        if (i == aux || i == aux2) {
          std::cout << "\033[0;"+red_color << sequence[i] << " \033[0m" << " ";
        }
        else std::cout << sequence[i] << " ";
      }
      std::cout << "\n";
    } 
    //--------------------------------------------------------------------------------
  }
  return sequence;
}



template <typename Clave> 
std::vector<Clave> bubbleSort(std::vector<Clave>& sequence, int size, int mode) {
  int aux, aux2;
  std::string red_color = "31m";

  for (int i = 1; i < size; i++) {
    for (int j = size-1; j >= i; j--) {
      if (sequence[j] < sequence[j-1]) {
        std::swap(sequence[j-1], sequence[j]);
        aux = j-1;
        aux2 = j;
      }
    }
    //Demonstration Mode = 1 ------------------------------------------------------
      if (mode == 1) {
        std::cout << "\nEvery modification will be shown on red\n";
        for (int k = 0; k < sequence.size(); k++) {
          if (k == aux || k == aux2) {
            std::cout << "\033[0;"+red_color << sequence[k] << " \033[0m" << " ";
          }
          else std::cout << sequence[k] << " ";
        }
        std::cout << "\n";
      } 
      //--------------------------------------------------------------------------------
  }
  return sequence;
}



template <typename Clave>
void heapify(int iterator, std::vector<Clave>& sequence, int size_seq) {
  int pos_max;

  while (2 * iterator <= size_seq) {
    int left  = 2 * iterator;
    int right = left + 1;

    if (left == size_seq) 
      pos_max = left;
    else if (sequence[left] > sequence[right])
      pos_max = left;
      else 
        pos_max = right;

    if (sequence[pos_max] <= sequence[iterator]) {
      break;
    }
    else {
      std::swap(sequence[iterator], sequence[pos_max]);
      iterator = pos_max;
    }
  }
}



template <typename Clave>
std::vector<Clave> heapSort(std::vector<Clave>& sequence, int size, int mode) {
  int half_size = size/2;
  int aux, aux2, iter;
  std::string red_color = "31m";

  for (int i = half_size-1; i >= 0; i--) {
    heapify(i, sequence, size);
  }

  for (int i = size-1; i >= 0; i--) {
    std::swap(sequence[0], sequence[i]);
    heapify(0, sequence, i-1);
    
    aux = 0;
    aux2 = i;
    //Demonstration Mode = 1 ------------------------------------------------------
    if (mode == 1) {
      std::cout << "\nEvery modification will be shown on red\n";
      for (int k = 0; k < sequence.size(); k++) {
        if (k == aux || k == aux2) {
          std::cout << "\033[0;"+red_color << sequence[k] << " \033[0m" << " ";
        }
        else std::cout << sequence[k] << " ";
      }
      std::cout << "\n";
    } 
    //--------------------------------------------------------------------------------
    
  }
  return sequence; 
}



template <typename Clave>
std::vector<Clave> quickSort(std::vector<Clave>& sequence, int begin, int end) {
  int new_begin = begin;
  int new_end   = end;
  Clave pivot = sequence[(new_begin + new_end) / 2];
  
  while (new_begin <= new_end) {

    while (sequence[new_begin] < pivot) new_begin++;
    while (sequence[new_end] > pivot) new_end--;

    if (new_begin <= new_end) {
      std::swap(sequence[new_begin], sequence[new_end]);
      new_begin++;
      new_end--;
    }
  }

  if (begin < new_end) quickSort(sequence, begin, new_end);
  if (new_begin < end) quickSort(sequence, new_begin, end);

  return sequence; 
}




template<typename Clave>
void deltaSort(int delta , std::vector<Clave>& sequence, int size) {
  Clave x_data;

  for (int i = delta; i < size; i++) {
    x_data = sequence[i];
    int j = i;

    while ((j >= delta) && (x_data < sequence[j-delta])) {
      sequence[j] = sequence[j-delta];
      j = j - delta;
    } 
    sequence[j] = x_data;
  } 
}



template <typename Clave>
std::vector<Clave> shellSort(float alfa, std::vector<Clave>& sequence, int size) {
  int delta = size * alfa;
  
  while (delta > 1){
    delta = delta / 2;
    deltaSort(delta, sequence, size);
  }
  
  return sequence;
}
