// Jiaqi Luo, 21/7, CS202, hw2, battle.cpp
// This file contains the functions of the battle class

#include "battle.h"
using namespace std;

// constructor
////set the players_list to NULL,num_of_players to 0
battle::battle() : players_list(NULL), num_of_player(0) {}

// constructor
// initialise the players_list using the num_of_playersas size
// input: a int vaule for number of players
battle::battle(const int num_of_player) {
  this->num_of_player = num_of_player;
  players_list = new deck *[num_of_player];
  for (int i = 0; i < num_of_player; ++i)
    players_list[i] = new deck();
}

// destructor
// if the players_list is not empty,
// delete all pointers in the array
// then delete the array
battle::~battle() {
  if (num_of_player != 0) {
    for (int i = 0; i < num_of_player; ++i) {
      delete players_list[i];
      players_list[i] = NULL;
    }
  }
  delete[] players_list;
  players_list = NULL;
}

// add a new card(the source) to the particular position of the players_list
// deponding on the index when the index is smaller than number of players
// input: a pointer to node, a int value for inde
void battle::add_card(node *source, int index) {
  if (index < num_of_player)
    players_list[index]->push(source);
}

// reurn the head of a particular elemeent of the players_list, deponding on the
// index
// input: a int valur for index
// output: a pointer to a node
node *battle::return_card(int index) { return players_list[index]->pop(); }

// display all the values of the heads in the array
// by all the display function of deck class
void battle::display_pair() {
  for (int i = 0; i < num_of_player; ++i) {
    cout << "player #" << i + 1 << ": ";
    players_list[i]->display();
  }
}

// compare the current ndoes in the array when each player plays a card
// player1 wins if player1's card is larger or player2's card is jokoer, and
// both are not 2
// player2 wins if player2's card is larger or player1's card is joker, and both
// are not 2
// war starts if there is a 2 or the values of two cards are the same
// return 0 if player1 wins;
// return 1 if player2 wins
// return 2 if a war happens
// return 3 if error
int battle::compare() {
  int player1 = players_list[0]->get_head_value();
  int player2 = players_list[1]->get_head_value();
  if (player1 > player2 && player1 != 2 && player1 != 100 && player2 != 2 &&
      player2 != 100)
    return 0;
  else if (player1 < player2 && player1 != 2 && player1 != 100 &&
           player2 != 2 && player2 != 100)
    return 1;
  else if (player1 != 100 && player2 == 100)
    return 0;
  else if (player1 == 100 && player2 != 100)
    return 1;
  else if (player1 == player2 || player1 == 2 || player2 == 2)
    return 2;
  else
    return 3;
}

// compare the cards in the array when a war happens
// player1 wins if player1's card is larger or a jokoer
// player2 wins if player2's card is larger or a jokoer
// a war happens if two cards have the same value or there is joker in all eight
// cards
// return -1 if no-winer
// return 0 if player1 wins;
// return 1 if player2 wins
// return 2 if a war happens
// return 3 if error
int battle::war_compare() {
  int player1 = players_list[0]->get_head_value();
  int player2 = players_list[1]->get_head_value();
  if (player1 > player2 && player1 != 2 && player1 != 100 && player2 != 2 &&
      player2 != 100)
    return 0;
  else if (player1 < player2 && player1 != 2 && player1 != 100 &&
           player2 != 2 && player2 != 100)
    return 1;
  else if (player1 != 100 && player2 == 100)
    return 1;
  else if (player1 == 100 && player2 != 100)
    return 0;
  else if (player1 == player2 && player1 != 100 && player2 != 100)
    return 2;
  else if (player1 == 100 && player2 == 100)
    return -1;
  else
    return 3;
}
