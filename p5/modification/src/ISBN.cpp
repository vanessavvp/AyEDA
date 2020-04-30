/**
 * PROJECT HEADER
 * @file ISBN.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#include "../include/ISBN.hpp"

#include <cmath>

Counter ISBN::counter;

ISBN::ISBN(void) {
  bookCode_ = rand() % 10000000000;
}



unsigned long ISBN::getBookCode(void) {
  return bookCode_;
}



ISBN::operator unsigned long() const {
  return bookCode_;
}



bool ISBN::operator ==(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ == ISBN.bookCode_) 
    return true;
  return false;
}



bool ISBN::operator <(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ < ISBN.bookCode_) 
    return true;
  return false;
}



bool ISBN::operator >(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ > ISBN.bookCode_) 
    return true;
  return false;
}



bool ISBN::operator <=(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ <= ISBN.bookCode_) 
    return true;
  return false;
}



bool ISBN::operator >=(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ >= ISBN.bookCode_) 
    return true;
  return false;
}



bool ISBN::operator !=(const ISBN& ISBN) const {
  ISBN::counter.inc();

  if (bookCode_ != ISBN.bookCode_) 
    return true;
  return false;
}