/**
 * PROJECT HEADER
 * @file DNI.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
 */

#ifndef INCLUDE_DNI_H
#define INCLUDE_DNI_H

#include <iostream>

#include "counter.hpp"

class DNI {
 public:
  DNI(void);
  ~DNI(void) {};
  
  operator unsigned long() const;
  bool operator == (const DNI& dni) const;
  bool operator <(const DNI& dni) const;
  bool operator >(const DNI& dni) const;
  bool operator <=(const DNI& dni) const;
  bool operator >=(const DNI& dni) const;
  bool operator !=(const DNI& dni) const;

  static Counter counter;

 private:
   unsigned long idNumber_;
};

#endif //INCLUDE_DNI_H