/**
 * PROJECT HEADER
 * @file DNI.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 14/05/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº6
 * Purpose: Implementación de un árbol binario de búsqueda (ABB)
 */

#include "../include/DNI.hpp"

#include <cmath>

Counter DNI::counter;

DNI::DNI(void) {
  idNumber_ = rand() % 100000000;
}



unsigned long DNI::getIdNumber(void) {
  return idNumber_;
}



void DNI::setIdNumber(unsigned long new_id_number) {
  idNumber_ = new_id_number;
}



DNI& DNI::operator =(int new_id_number)  {
	idNumber_= new_id_number;
	return *this;
}



DNI::operator unsigned long() const {
  return idNumber_;
}



bool DNI::operator ==(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ == DNI.idNumber_) 
    return true;
  return false;
}



bool DNI::operator <(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ < DNI.idNumber_) 
    return true;
  return false;
}



bool DNI::operator >(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ > DNI.idNumber_) 
    return true;
  return false;
}



bool DNI::operator <=(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ <= DNI.idNumber_) 
    return true;
  return false;
}



bool DNI::operator >=(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ >= DNI.idNumber_) 
    return true;
  return false;
}



bool DNI::operator !=(const DNI& DNI) const {
  DNI::counter.inc();

  if (idNumber_ != DNI.idNumber_) 
    return true;
  return false;
}