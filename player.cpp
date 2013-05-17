//
//  player.cpp
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#include "player.h"
using namespace std;

Player::Player(){
   string n;
   cout << "Enter the player's name." << endl;
   cin >> n;
   name = n;
   
   ships.push_back(new AircraftCarrier);
   ships.push_back(new Battleship);
   ships.push_back(new Submarine);
   ships.push_back(new Destroyer);
   ships.push_back(new PatrolBoat);
   
   for (int i=0; i<ships.size(); i++){
      board.placeShip(*ships.at(i));
   }
}

Player::Player(string n) : name(n) {
   ships.push_back(new AircraftCarrier);
   ships.push_back(new Battleship);
   ships.push_back(new Submarine);
   ships.push_back(new Destroyer);
   ships.push_back(new PatrolBoat);
   
   for (int i=0; i<ships.size(); i++){
      board.placeShip(*ships.at(i));
   }
}

Player::~Player(){
   for (int i=0; i<ships.size(); i++){
      delete ships.at(i);
   }
   ships.clear();
}

string Player::getName(){
   return name;
}

void Player::drawBoardEnemy(){
   board.drawBoardEnemy();
}

void Player::fire(){
   drawBoardEnemy();
   board.fire();
}

bool Player::defeated(){
   bool rtrn = true;
   for (int i=0; i<ships.size(); i++) {
      rtrn = rtrn && ships.at(i)->isSunk();
   }
   return rtrn;
}