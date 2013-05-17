//
//  board.h
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#ifndef __Battleship__board__
#define __Battleship__board__

#include <iostream>
#include <vector>
#include <string>
#include "ship.h"
#include "cell.h"
using namespace std;


class Board{
   vector< vector<Cell*> > boardVec;
   bool validPosition(string pos);
   bool validShipPlacement(string pos);
public:
   Board();
   ~Board();
   void drawBoardFriendly();
   void drawBoardEnemy();
   void placeShip(Ship& s);
   void fire();
};


#endif /* defined(__Battleship__board__) */
