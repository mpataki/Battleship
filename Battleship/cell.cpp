//
//  cell.cpp
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#include "cell.h"

Cell::Cell() : ship(NULL), symbol(' '){}

Cell::Cell(string pos) : pos(pos), ship(NULL), symbol(' '){}

bool Cell::vacant(){
   return ship == NULL;
}

char Cell::getSymbol(){
   return symbol;
}

void Cell::setSymbol(char c){
   symbol = c;
}

Ship* Cell::getShip(){
   return ship;
}

void Cell::setShip(Ship* s) {
   ship = s;
}

string Cell::getPos(){
   return pos;
}