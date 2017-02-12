// Jiaqi Luo, 21/7, CS202, hw2, deck.h
// This file contains the decleration of the deck class

#include "node.h"

class deck {
public:
  // constructor
  // set head to NULL
  deck();
  // constructor
  // set the node as same as the source
  // input: a node object
  deck(const node &source);
  // destructor
  ~deck();
  // creat a set of poker which contains 52 cards from 1 to 13,
  // and 2 jokers
  void create_a_set_of_poker();
  // push a new node into the deck as the head pointer
  // input: a pointer to a node
  void push(node *head);
  // pop the head of the deck and return it
  // output: a pointer to a card which is removed from the head of the deck
  node *pop();
  // display the curent deck from the head to the end
  // output: display all the value of cards in the deck
  void display();
  // return the value of the pointer to head
  // output: the value of the head
  int get_head_value();

protected:
  node *head; // a pointer to the head of the deck
  // the display function that is invoked by wrapper function
  // input: a pointer to the head of the deck
  // output: display the value of cards in the deck
  void display(node *head);
};
