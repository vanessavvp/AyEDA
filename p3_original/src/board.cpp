/**
 * PROJECT HEADER
 * @file board.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 26/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº3
 * Purpose: The game of life generalized
 */

#include "../include/board.h"
#include "../include/cell.h"

Board::Board(int row, int col) 
{
  row_ = row;
  col_ = col;
  table_ = new Cell*[(row_+2)*(col_+2)];
  for (int i = 0; i < row_+2; i++) {
    for (int j = 0; j < col_+2; j++) {
      table_[i*(col_+2)+j] = new Cell(i,j); //Se colocan todas las celulas muertas 
    }
  }         
}



Board::~Board(void) 
{
  for (int i = 0; i < row_ + 2; i++) {
    for (int j = 0; j < col_ + 2; j++) {
      delete table_[i*(col_+2)+j];
    }
  }
  delete[] table_;
}



void Board::setCol(int col)
{
  col_ = col;
}



void Board::setRow(int row)
{
  row_ = row;
}



int Board::getCol(void) 
{
  return col_;
}



int Board::getRow(void)
{
  return row_;
}



int Board::pos(int i, int j)
{
  return (i * (getCol() + 2) + j);
}



Cell** Board::getTable(void)
{
  return table_;
}



Cell* Board::operator[](int position) 
{
  return table_[position];
}



void Board::startGameofLife(int& numberOfTurns) 
{
  std::cout << "Turno 0\n";
  for (int i = 1; i <= getRow(); i++) {
    for (int j = 1; j <= getCol(); j++) {
        //getTable()[i * (getCol() + 2) + j]->show(std::cout);
        getTable()[pos(i,j)]->show(std::cout);
    }
    std::cout << "\n";
  }
  for (int actualTurn = 1; actualTurn <= numberOfTurns; actualTurn++) {
    //PRIMER RECORRIDO A LA MALLA, se cuentan las celulas vecinas vivas de cada una de las 
    //celulas
    for (int i = 1; i <= getRow(); i++) {
      for (int j = 1; j <= getCol(); j++) {
        //table_[i * (col_ + 2) + j]->countNeighbors(*this);
        table_[pos(i,j)]->countNeighbors(*this);
      }
    }
    //SEGUNDO RECORRIDO A LA MALLA, cada celula actualiza su estado y se elimina del tablero para ser 
    //sustituida
    for (int i = 1; i <= getRow(); i++) {
      for (int j = 1; j <= getCol(); j++) {
        int nextNeighborAlive = table_[i * (col_ + 2) + j]->updateStatus();
        delete table_[i * (col_ + 2) + j];
        table_[i * (col_ + 2) + j] = table_[i * (col_ + 2) + j]->createCell(nextNeighborAlive, i, j);
      }
    }
    //TERCER RECORRIDO A LA MALLA, se enseña la malla por pantalla
    std::cout << "Turno: " << actualTurn << "\n";
    for (int i = 1; i <= getRow(); i++) {
      for (int j = 1; j <= getCol(); j++) {
        getTable()[i * (getCol() + 2) + j]->show(std::cout);
      }
      std::cout << "\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //90
  }
  std::cout << "GAME OVER :(\n";  
}



Cell* Board::getCell(int rowInx, int colInx)
{
  return table_[pos(rowInx, colInx)];
}



void Board::activarcelula(int type, int i, int j)
{
  table_[i  * (col_ + 2) + j] = table_[i * (col_ + 2) + j]->createCell(type, i,j);
}



void Board::initializeCoordinates(int& initialAliveCells)
{
  int newCell = 0;
  int rowInx, colInx, typeOfCell;

  std::cout << "Introduce the inicial alive cells coordinates: \n";
  while (newCell < initialAliveCells) {
    std::cout << "Row: ";
    std::cin >> rowInx;
    std::cout << "Col: ";
    std::cin >> colInx;
    std::cout << "Type of cell: ";
    std::cin >> typeOfCell;

    this->activarcelula(typeOfCell, rowInx, colInx);

    newCell ++;
  }
}
