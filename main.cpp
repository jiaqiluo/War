// Jiaqi Luo,22/7, CS202, hw2, main.cpp
// This file contains the main function, which is used to test codes

#include "manage.h"
using namespace std;

int main() {
  // start test the program
  // the number of players is 2(default)
  manage test;
  // create a set of pokers, shuffle and spilt to two players
  test.start();
  // start game
  // each plays a card,
  // if both play a card successfuly, continue to judge the winer of this round,
  // and start war if necessary
  // repeat the process until one wins
  while (test.play_a_card() == -1) {
    if (test.judge() == 2)
      test.war();
  }
  return 0;
}
