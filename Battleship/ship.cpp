//
//  ship.cpp
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#include "ship.h"

Ship::Ship() : size(0), hits(0) {}

int Ship::getSize(){
   return size;
}

string Ship::getType(){
   return type;
}

void Ship::hit(){
   hits++;
}

bool Ship::isSunk(){
   return hits >= size;
}

char Ship::getSymbol(){
   return symbol;
}

AircraftCarrier::AircraftCarrier() : Ship() {
   size = 5;
   hits = 0;
   type = "Aircraft Carrier";
   symbol = 'A';
}

Battleship::Battleship() : Ship() {
   size = 4;
   hits = 0;
   type = "Battleship";
   symbol = 'B';
}

Submarine::Submarine() : Ship() {
   size = 3;
   hits = 0;
   type = "Submarine";
   symbol = 'S';
}

Destroyer::Destroyer() : Ship() {
   size = 3;
   hits = 0;
   type = "Destroyer";
   symbol = 'D';
}

PatrolBoat::PatrolBoat() : Ship() {
   size = 2;
   hits = 0;
   type = "Patrol Boat";
   symbol = 'P';
}