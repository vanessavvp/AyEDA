/**
 * PROJECT HEADER
 * @file board.cpp
 * @author: Vanessa Valentina Villalba Perez
 * Contact:  alu0101265704@ull.edu.es
 * @date: 10/03/2020
 * Subject: Algoritmos y Estructuras de Datos Avanzadas
 * Practice: Numberº2
 * Purpose: Game of life
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
      table_[i*(col_+2)+j] = new Cell(i,j);
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
  //return (i * (getRow() + 2) + j);
  return (i * (getCol() + 2) + j);

}

Cell* Board::operator[](int position) 
{
  return table_[position];
}

void Board::startGameofLife(int& numberOfTurns) 
{
  int initialAliveCells, rowInx, colInx;
  
  printBoard(0);
  std::cout << "------------------------------------------------------------------------------\n";
  for (int actualTurn = 1; actualTurn <= numberOfTurns; actualTurn++) {
    double counter = 0; //MOD
    //Primer recorrido a la malla, se cuentan las celulas vecinas vivas de cada una de las celulas
    for (int i = 1; i <= getRow(); i++) {
      for (int j = 1; j <= getCol(); j++) {
        counter += table_[pos(i,j)]->countNeighbors(*this);
      }
    }
    //SEGUNDO RECORRIDO A LA MALLA, cada celula actualiza su estado si fuera necesario
    for (int i = 1; i <= getRow(); i++) {
      for (int j = 1; j <= getCol(); j++) {
        table_[pos(i,j)]->updateStatus();
      }
    }
    //TERCER RECORRIDO A LA MALLA, se enseña la malla por pantalla
    printBoard(actualTurn); 
    
    //MOD: Calculamos la media de entre todas las celulas del tablero y sus vecinas
    std::cout << "La media de células vecinas en este turno es: " << (counter / (row_ * col_)) << "\n------------------------------------------------------------------------------";
  }
  std::cout << "\nGAME OVER :(\n";  
}

Cell* Board::wantedPosition(int rowInx, int colInx)
{
  return table_[pos(rowInx, colInx)];
}

bool Board::isAliveCell(int rowInx, int colInx) 
{
  if (table_[pos(rowInx, colInx)]->getStatus() == 1) 
    return true;
  return false;
}

void Board::printBoard(int turnNumber) 
{
  std::cout << "\nTurn number " << turnNumber << "\n";
  for (int i = 1; i <= getRow(); i++) {
    for (int j = 1; j <= getCol(); j++) {
      if (!isAliveCell(i,j)) {
        std::cout << " ";
      }
      else {
        std::cout << "x";
      }
    }
    std::cout << "\n";
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //90
}

/**
 * @brief Método para enseñar por pantalla la malla(tablero) con dimensiones
 * [(N+2)*(M+2)]
 * 
 */
void Board::constructionBoard(void)
{
  std::cout << "Board under construction...\n";
  for (int rows = 0; rows < getRow()+2; rows++) {
    for (int col = 0; col < getCol()+2; col++) {
      std::cout << table_[rows*(getCol()+2)+col]->getStatus();
    }
    std::cout << "\n";
  }
}

/**
 * @brief Método para inicializar el tablero con células vivas a partir
 * de los datos introducidos por el usuario
 * 
 * @param initialAliveCells 
 */
void Board::initializeCoordinates(int& initialAliveCells) 
{
  int newCell = 0;
  int rowInx, colInx;

  std::cout << "Introduce the inicial alive cells coordinates: \n";
  while (newCell < initialAliveCells) {
    std::cout << "Row: ";
    std::cin >> rowInx;
    std::cout << "Col: ";
    std::cin >> colInx;
    //Verificamos que las coordenadas no se correspondan con una celula que
    //ya se encuentre viva y que se encuentren dentro de las dimensiones de
    //la malla 
    if (this->isAliveCell(rowInx, colInx)) {
      std::cout << "That cell is already alive!\n";
      std::cout << "Enter the coordenates of the alive cell again\n";
    }
    else if (this->isOutOfRange(rowInx, colInx)) {
      std::cout << "You have enter coordenates out of range\n";
      std::cout << "Enter the coordenates of the alive cell again\n";
    }
    else {
      this->wantedPosition(rowInx, colInx)->setStatus(1);
      newCell++;
    }
  }
}

/**
 * @brief Método que verifica si la coordenada introducida se encuentra fuera
 * de las dimensiones de la malla(tablero)
 * 
 * @param rowInx 
 * @param colInx 
 * @return true 
 * @return false 
 */
bool Board::isOutOfRange(int rowInx, int colInx)
{
  if ((this->getCol() < colInx) || (this->getRow() < rowInx))
    return true;
  return false;
}
