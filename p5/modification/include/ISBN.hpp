/**
 * PROJECT HEADER
 * @file ISBN.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#ifndef INCLUDE_ISBN_H
#define INCLUDE_ISBN_H

#include <iostream>

#include "counter.hpp"

class ISBN {
 public:
  ISBN(void);
  ~ISBN(void) {};
  
  unsigned long getBookCode(void);
  operator unsigned long() const;
  bool operator == (const ISBN& isbn) const;
  bool operator <(const ISBN& isbn) const;
  bool operator >(const ISBN& isbn) const;
  bool operator <=(const ISBN& isbn) const;
  bool operator >=(const ISBN& isbn) const;
  bool operator !=(const ISBN& isbn) const;

  static Counter counter;

 private:
   unsigned long bookCode_;
};

#endif //INCLUDE_ISBN_H