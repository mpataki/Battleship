//
//  ship.h
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#ifndef __Battleship__ship__
#define __Battleship__ship__

#include <iostream>
#include <string>
using namespace std;

class Ship{
protected:
   int size;
   int hits;
   string type;
   char symbol;
public:
   Ship();
   int getSize();
   string getType();
   void hit();
   bool isSunk();
   char getSymbol();
};

class AircraftCarrier : public Ship{
public:
   AircraftCarrier();
};

class Battleship : public Ship{
public:
   Battleship();
};

class Submarine : public Ship{
public:
   Submarine();
};

class Destroyer : public Ship{
public:
   Destroyer();
};

class PatrolBoat : public Ship{
public:
   PatrolBoat();
};

#endif /* defined(__Battleship__ship__) */
