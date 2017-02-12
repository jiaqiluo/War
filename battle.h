// Jiaqi Luo, 21/7, CS202, hw2, battle.h
// This file contains the decleration of the battle class

#include "player.h"

class battle {
public:
  // constructor
  // set the players_list to NULL,num_of_players to 0
  battle();
  // constructor
  // initialise the players_list using the num_of_playersas size
  // input: a int vaule for number of players
  battle(const int num_of_players);
  // destructor
  ~battle();
  // add a new card(the source) to the particular position of the players_list
  // deponding on the index
  // input: a pointer to node, a int value for index
  void add_card(node *source, int index);
  // reurn the head of a particular elemeent of the players_list, deponding on
  // the index
  // input: a int valur for index
  // output: a pointer to a node
  node *return_card(int index);
  // display all the values of the heads in the array
  void display_pair();
  // compare the current ndoes in the array when each player plays a card
  // output:
  // return 0 if player1 wins;
  // return 1 if player2 wins
  // return 2 if a war happens
  // return 3 if error
  int compare();
  // compare the cards in the array when a war happens
  // return -1 if no-winer
  // return 0 if player1 wins;
  // return 1 if player2 wins
  // return 2 if a war happens
  // return 3 if error
  int war_compare();

protected:
  deck **players_list; // dynamic allocated arry of poitners to deck
  int num_of_player;   // the number of players
};
