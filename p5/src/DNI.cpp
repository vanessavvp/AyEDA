/**
 * PROJECT HEADER
 * @file DNI.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact: alu0101265704@ull.edu.es
 * @date: 30/04/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº5
 * Purpose: Sorting methods
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