/**
 * PROJECT HEADER
 * @file counter.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#ifndef INCLUDE_COUNTER_H
#define INCLUDE_COUNTER_H

#include <iostream>

class Counter {
 public:
  Counter();
  ~Counter(){};

  void reset(void);
  void inc(void);
  void inc(int amount_to_increase);
  int  getQuantity(void);

 private:
  int quantity_;
};

#endif //INCLUDE_COUNTER_H