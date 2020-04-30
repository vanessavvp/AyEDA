/**
 * PROJECT HEADER
 * @file counter.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include <limits>

#include "../include/counter.hpp"

Counter::Counter(void) {
  reset();
}



int Counter::getQuantity(void) {
  return quantity_;
}



int Counter::getMin(void) {
  return min_;
}



int Counter::getMax(void) {
  return max_;
}



void Counter::setMin(int& newMin) {
  min_ =  newMin;
}



void Counter::setMax(int& newMax) {
  max_ =  newMax;
}



void Counter::reset(void) {
  quantity_   = 0;
  min_        = INT16_MAX;
  max_        = INT16_MIN;
  media_      = 0;
  testNumber_ = 0;
}



void Counter::resetQuantity(void) {
  quantity_ = 0;
}



void Counter::inc(void) {
  quantity_++;
}



void Counter::inc(int amount_to_increase) {
  quantity_ += amount_to_increase;
}



void Counter::calculateStatistics(void) {
  if (quantity_ < min_)
    min_ = quantity_;

  if (quantity_ > max_)
    max_ = quantity_;

  media_ += quantity_;
  testNumber_ ++;
}



void Counter::showStatisticsResults(std::string& method_name) {
  std::cout << std::setw(10) << method_name << std::setw(10) << min_ << std::setw(16) << media_/testNumber_;
  std::cout << std::setw(10) << max_ << "\n";
}
