// Jiaqi Luo, 21/7, CS202, hw2, manage.h
// This file contains the decleration of the manage class

#include "battle.h"

class manage {
public:
  manage();
  // destructor
  ~manage();
  // start to game
  // output: create a set of cards
  // and splilt the cards to players' hands
  void start();
  // each play play a card
  // return 0 if player2 wins(player1 doesn't have cards)
  // return 1 if player1 wins(player2 doesn't have cards
  // return -1 if both have cards
  // return 2 if both don't have cards
  // return 3 if no cards on battl
  int play_a_card();
  // junge the winner of the stage of playing a card
  // return 0 if player1 wins
  // return 1 if player2 wins
  // return 2 if new war happens
  int judge();
  // judge the result of the stage of war
  // return -1 if no-winer
  // return 0 if player1 wins;
  // return 1 if player2 wins
  // return 2 if a war happens
  // return 3 if erro
  int war_judge();
  // manage the war
  // each player plays four cards
  // if one doesn't have enoug cards, he lost
  // if both have enough cards, start a new war and coninue gam
  void war();

protected:
  int num_of_players;         // the number of players
  deck all_cards;             // for the orginal pokers
  cll_node *player1;          // player1's hand
  cll_node *player2;          // player2's hand
  players players_cll;        // all players
  battle in_battle_cards;     // the battle object for managing the battle
  int num_of_cards_in_battle; // the number of cards in the battle
};
