//
//  cell.h
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#ifndef __Battleship__Cell__
#define __Battleship__Cell__

#include <iostream>
#include "ship.h"
using namespace std;

class Cell{
   Ship* ship;
   char symbol;
   string pos;
public:
   Cell();
   Cell(string pos);
   ~Cell();
   bool vacant();
   char getSymbol();
   void setSymbol(char c);
   Ship* getShip();
   void setShip(Ship* s);
   string getPos();
};


#endif /* defined(__Battleship__Cell__) */
