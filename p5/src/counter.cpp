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

#include "../include/counter.hpp"

Counter::Counter(void) {
  quantity_ = 0;
}


void Counter::reset(void) {
  quantity_ = 0;
}


void Counter::inc(void) {
  quantity_++;
}


void Counter::inc(int amount_to_increase) {
  quantity_ += amount_to_increase;
}


int Counter::getQuantity(void) {
  return quantity_;
}