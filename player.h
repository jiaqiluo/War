// Jiaqi Luo, 21/7, CS202, hw2, player.h
// this file contains the decleration of the cll_node class and the players
// class

#include "deck.h"

class cll_node {
public:
  // constructor
  // set current_index and top_index to 0,next to NULL
  cll_node();
  // constructor
  // copy a cll_ndoe to the new one
  // input: a cll_node object
  cll_node(const cll_node &source);
  // destructor
  ~cll_node();
  // add a new node to the hand array
  // input: a pointer to node
  void add_card(node *source);
  // remove a card from the hand and return a pointer to this node
  // output: a pointer to the origianl head node
  node *play_a_card();
  // return the next cll_node
  cll_node *goto_next();
  // set the next pointer to cll_node in the linear linked list
  // input: a pointer to next cll_node
  void set_next(cll_node *next);
  // display all the number of nodes in the cll node
  void display();
  // check whether there is a joker in the array
  // output: true if there is a joker, else return false
  bool check_joker();

protected:
  node *hand[1000];  // a array of cards
  int current_index; // the current index of node in the array
  int top_index;     // the top index of nodes in the array
  cll_node *next;
};

class players {
public:
  // constructor
  // set rear to NULL, num_of_player to 0
  players();
  // destructor
  ~players();
  // add a new cll_node as the new head of the CLL
  // input: a pointer to a cll_node
  void add(cll_node *new_player);
  // return the head in the CLL by argument
  // output:
  // return 0 if player1 doesn't have card
  // return 1 if player2 doesn't have card
  // return 2 if both doesn't have card
  // return -1 if both have
  // return 3 if the source is empty
  int play_a_card(deck &a_deck);
  // display all cards of all players
  void display();
  // add a new node to the head of a particular player's hand
  // input: the pointer to soruce node, the index of the receiver
  // 0 - player1
  // 1 - player2
  void add_card_to_a_player(node *source, int player_index);
  // check if there is a joker in the CLL
  // output:
  // ture if there is a joker
  // else false
  bool check_joker();

protected:
  cll_node *rear;    // a pointer to cll_node as the rear of the CLL
  int num_of_player; // the number of players
};
