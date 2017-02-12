// Jiaqi Luo, 21/7, CS202, hw2, manage.cpp
// This file contains the functions of the card class and the manage clas
#include "manage.h"
using namespace std;

// constructor
// set num_of_players an num_of_cards_in_battle to 0,
// player1 and player2 to NULL.
manage::manage()
    : num_of_players(2), player1(NULL), player2(NULL), in_battle_cards(2),
      num_of_cards_in_battle(0) {}

// destructor
// deelete player1 and player2 if exist
manage::~manage() {
  if (player1) {
    delete player1;
    player1 = NULL;
  }
  if (player2) {
    delete player2;
    player2 = NULL;
  }
}

// start to game
// output: create a set of cards
// and splilt the cards to players' hand
void manage::start() {
  all_cards.create_a_set_of_poker();
  cout << "\nthe deck is: ";
  all_cards.display();
  int i = 54 / num_of_players;        // to see how many cards each player has
  cll_node *player1 = new cll_node(); // declear one player here
  cll_node *player2 = new cll_node(); // another player
  for (int t = 0; t < i; t++)
  // add cards to each player(the array of cards in the cll_node)
  {
    player1->add_card(all_cards.pop());
    player2->add_card(all_cards.pop());
  }

  players_cll.add(player1);
  players_cll.add(player2);
  players_cll.display();
  cout << "\n--------start---------\n";
}
// each play play a card
// return 0 if player2 wins(player1 doesn't have cards)
// return 1 if player1 wins(player2 doesn't have cards
// return -1 if both have cards
// return 2 if both don't have cards
// return 3 if no cards on battle
int manage::play_a_card() {
  deck temp;
  int result = players_cll.play_a_card(temp);
  num_of_cards_in_battle += 2;
  if (result == 0) {
    cout << "\nplayer 1 doesn't have enough cards." << endl;
    cout << "\nplayer 2 wins!" << endl;
    return 0;
  } else if (result == 1) {
    cout << "\nplayer 2 doesn't have enough cards." << endl;
    cout << "\nplayer 1 wins!" << endl;
    return 1;
  } else if (result == -1) {
    for (int b = 0; b < num_of_players; ++b)
      in_battle_cards.add_card(temp.pop(), b);
    return -1;
  } else if (result == 2)
    cout << "\nboth don't have cards, game over." << endl;
  else if (result == 3)
    cout << "\nno cards in ballte cards" << endl;
}

// judge the result of the stage of playing a card
// display all cards in battle,
// then add all cards to the winner,
// return 0 if player1 wins
// return 1 if player2 wins
// return 2 if new war happens
int manage::judge() {
  int is_a_war = in_battle_cards.compare();
  cout << "\n\n------------new rount-------------" << endl;
  cout << "\ncards in battle: ";
  in_battle_cards.display_pair();
  // player1 wins cards
  if (is_a_war == 0) {
    for (int i = 0; i < num_of_cards_in_battle / 2; ++i) {
      players_cll.add_card_to_a_player(in_battle_cards.return_card(0), 0);
      players_cll.add_card_to_a_player(in_battle_cards.return_card(1), 0);
    }
    num_of_cards_in_battle = 0;
    cout << "\n------player1 wins cards----------\n";
    cout << "current cards:\n";
    players_cll.display();
    return 0;
  }
  // player2 wins cards
  if (is_a_war == 1) {
    for (int i = 0; i < num_of_cards_in_battle / 2; ++i) {
      players_cll.add_card_to_a_player(in_battle_cards.return_card(0), 1);
      players_cll.add_card_to_a_player(in_battle_cards.return_card(1), 1);
    }
    num_of_cards_in_battle = 0;
    cout << "\n-------player2 wins cards----------\n";
    cout << "current cards:\n";
    players_cll.display();
    return 1;
  }
  // a war starts
  if (is_a_war == 2) {
    cout << "\n-------WAR----------\n";
    return 2;
  }
}

// judge the result of the stage of war
// return -1 if no-winer
// return 0 if player1 wins;
// return 1 if player2 wins
// return 2 if a war happens
// return 3 if error
int manage::war_judge() {
  int is_a_war = in_battle_cards.war_compare();
  cout << "\n\nin battle cards: ";
  in_battle_cards.display_pair();
  // player1 wins cards
  if (is_a_war == 0) {
    for (int i = 0; i < num_of_cards_in_battle / 2; ++i) {
      players_cll.add_card_to_a_player(in_battle_cards.return_card(0), 0);
      players_cll.add_card_to_a_player(in_battle_cards.return_card(1), 0);
    }
    num_of_cards_in_battle = 0;
    cout << "\n------player1 wins cards----------\n";
    players_cll.display();
    return 0;
  }
  // player2 wins cards
  if (is_a_war == 1) {
    for (int i = 0; i < num_of_cards_in_battle / 2; ++i) {
      players_cll.add_card_to_a_player(in_battle_cards.return_card(0), 1);
      players_cll.add_card_to_a_player(in_battle_cards.return_card(1), 1);
    }
    num_of_cards_in_battle = 0;
    cout << "\n-------player2 wins cards----------\n";
    players_cll.display();
    return 1;
  }
  // a war starts
  if (is_a_war == 2) {
    cout << "\n---------WAR----------\n";
    return 2;
  }
  // no-winer

  if (is_a_war == -1 || players_cll.check_joker() == true) {
    for (int i = 0; i < num_of_cards_in_battle / 2; ++i) {
      players_cll.add_card_to_a_player(in_battle_cards.return_card(0), 0);
      players_cll.add_card_to_a_player(in_battle_cards.return_card(1), 1);
    }
    num_of_cards_in_battle = 0;
    players_cll.display();
    return -1;
  }
}

// manage the war
// each player plays four cards
// if one doesn't have enoug cards, he lost
// if both have enough cards, start a new war and coninue game
void manage::war() {
  if (play_a_card() == -1) {
    if (play_a_card() == -1) {
      if (play_a_card() == -1) {
        if (play_a_card() == -1) {
          if (war_judge() == 2)
            war();
        }
      }
    }
  }
}
