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
#include <iomanip>

class Counter {
 public:
  Counter();
  ~Counter(){};

  int getMin(void);
  int getMax(void);
  int getQuantity(void);

  void setMin(int& newMin);
  void setMax(int& newMax);

  void reset(void);
  void inc(void);
  void inc(int amount_to_increase);
  void resetQuantity(void);
  void calculateStatistics(void);
  void showStatisticsResults(std::string& method_name);

 private:
  int quantity_;
  int min_;
  int max_;
  float media_;
  int testNumber_;
};

#endif //INCLUDE_COUNTER_H