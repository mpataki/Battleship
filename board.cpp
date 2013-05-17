//
//  board.cpp
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#include "board.h"
using namespace std;

class OutOfBounds {
public:
   OutOfBounds(){}
};

class BadPos {
public:
   BadPos(string str): str(str) { }
   string getStr() { return str; }
private:
   string str;
};

class NoVacancy{
public:
   NoVacancy(Cell& c) : c(&c){ }
   string getPos() {
      return c->getPos();
   }
private:
   Cell* c;
};

Board::Board(){
   boardVec.resize(10);    // resize and initialize the 2D board vector
   string pos;
   for (int i=0; i<10; i++){
      boardVec.at(i).resize(10);
      for (int k=0; k<10; k++){
         pos.clear();
         pos.push_back(static_cast<char>(65+i));
         pos.push_back(static_cast<char>(48+k));
         boardVec[i][k] = new Cell(pos);
      }
   }
}

Board::~Board(){
   for (int i=0; i<10; i++) {
      for (int k=0; k<10; k++) {
         free( boardVec[i][k] );
         boardVec[i][k] = NULL;
      }
   }
}

void Board::drawBoardFriendly(){
   cout << "    0   1   2   3   4   5   6   7   8   9  " << endl;
   cout << "  -----------------------------------------" << endl;
   for (int i=0; i<10; i++){
      cout << (char)(i+65) << " |";
      for (int k=0; k<10; k++){
         cout << " " << boardVec[i][k]->getSymbol() << " |";
      }
      cout << endl;
      cout << "  -----------------------------------------" << endl;
   }
}

void Board::drawBoardEnemy(){
   cout << "    0   1   2   3   4   5   6   7   8   9  " << endl;
   cout << "  -----------------------------------------" << endl;
   for (int i=0; i<10; i++){
      cout << (char)(i+65) << " |";
      for (int k=0; k<10; k++){
         char symbol = boardVec[i][k]->getSymbol();
         if (symbol == 'X' || symbol == 'O'){
            cout << " " << symbol << " |";
         } else {
            cout << "   |";
         }
      }
      cout << endl;
      cout << "  -----------------------------------------" << endl;
   }
}

void Board::placeShip(Ship& s){
   drawBoardFriendly();
   string pos;
   cout << "Place your " << s.getType() << "[A-J][0-9][R,D]" << endl;
   cin >> pos;
   try {
      if (!validShipPlacement(pos)) throw BadPos(pos);
      int row = pos.at(0) - 65;
      int col = pos.at(1) - 48;
   
      if (pos.at(2) == 'R'){

         if (col + s.getSize() > 10) throw OutOfBounds();
         
         for (int i=col; i<(col + s.getSize()); i++){
            if (!boardVec[row][i]->vacant()) {
               throw NoVacancy(*(boardVec[row][i]));
            }
            boardVec[row][i]->setSymbol(s.getSymbol());
            boardVec[row][i]->setShip(&s);
         }
      
      } else if (pos.at(2) == 'D'){
         
         if (row + s.getSize() > 10) throw OutOfBounds();
         
         for (int i=row; i<(row + s.getSize()); i++){
            if (!boardVec[i][col]->vacant()) {
               throw NoVacancy(*(boardVec[i][col]));
            }
            boardVec[i][col]->setSymbol(s.getSymbol());
            boardVec[i][col]->setShip(&s);
         }
      }
   }
   catch (BadPos bp){
      cerr << bp.getStr() << " not a valid ship position. Try again." << endl;
      placeShip(s);
   }
   catch (OutOfBounds){
      cerr << "Placement out of bounds." << endl;
      placeShip(s);
   }
   catch (NoVacancy nv){
      cerr << "The position " << nv.getPos() << " has not vacant. Try again." << endl;
      placeShip(s);
   }
}

void Board::fire(){
   string pos;
   cout << "Choose a position to fire on. [A-J][0-9]" << endl;
   cin >> pos;
   try {
      if (!validPosition(pos)) throw BadPos(pos);
      int row = pos.at(0) - 65;
      int col = pos.at(1) - 48;
      
      if (boardVec[row][col]->vacant()) {
         boardVec[row][col]->setSymbol('O');
         cout << "Miss!" << endl;
      } else {
         if (boardVec[row][col]->getSymbol() == 'X'){
            cout << "Position already fired apon. Try again." << endl;
            fire();
         } else {
            boardVec[row][col]->setSymbol('X');
            boardVec[row][col]->getShip()->hit();
            cout << "Hit!" << endl;
         }
         if (boardVec[row][col]->getShip()->isSunk()){
            cout << "You sunk your enemy's " << boardVec[row][col]->getShip()->getType() << "!" << endl;
         }
      }
      
   }
   catch (BadPos bp){
      cout << bp.getStr() << " not a valid ship position. Try again." << endl;
      fire();
   }
}

bool Board::validPosition(string pos){
   if (pos.length() != 2) {
      return false;
   }
   if ((65 <= pos.at(0) && pos.at(0) <= 75) &&
       (48 <= pos.at(1) && pos.at(1) <= 57)){
      return true;
   }
   return false;
}

bool Board::validShipPlacement(string pos){
   if (pos.length() != 3) { return false; }
   if ((65 <= pos.at(0) && pos.at(0) <= 75) &&
       (48 <= pos.at(1) && pos.at(1) <= 57) &&
       (pos.at(2) == 'R' ||
        pos.at(2) == 'D')){
      return true;
   }
   return false;
}










