/**
 * PROJECT HEADER
 * @file DNI.hpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#ifndef INCLUDE_DNI_H
#define INCLUDE_DNI_H

#include <iostream>

#include "counter.hpp"

class DNI {
 public:
  DNI(void);
  ~DNI(void) {};
  
  unsigned long getIdNumber(void);
  void setIdNumber(unsigned long new_id_number);
  operator unsigned long() const;
  DNI& operator =(int new_id_number);
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