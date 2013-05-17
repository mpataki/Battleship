//
//  main.cpp
//  Battleship
//
//  Created by Mat on 2012-12-13.
//
//

#include <iostream>
#include "board.h"
#include "player.h"
using namespace std;

int main(int argc, const char * argv[])
{
   Player p1;
   Player p2;
   while (!p1.defeated() && !p2.defeated()) {
      cout << p1.getName() << "'s turn to fire!" << endl;
      p2.fire();
      if (!p2.defeated()){
         cout << p2.getName() << "'s turn to fire!" << endl;
         p1.fire();
      }
   }
   if (p1.defeated()){
      cout << p1.getName() << " defeated! " << p2.getName() << " wins!" << endl;
   } else {
      cout << p2.getName() << " defeated! " << p1.getName() << " wins!" << endl;
   }
   return 0;
}

