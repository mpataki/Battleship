//
//  player.h
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#ifndef __Battleship__player__
#define __Battleship__player__

#include <iostream>
#include <string>
#include <vector>
#include "board.h"
#include "ship.h"

class Player {
   string name;
   Board board;
   vector<Ship*> ships;
public:
   Player();
   Player(string n);
   ~Player();
   string getName();
   void drawBoardEnemy();
   void fire();
   bool defeated();
};

#endif /* defined(__Battleship__player__) */
