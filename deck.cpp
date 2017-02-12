// Jiaqi Luo, 21/7, CS202, hw2, deck.cpp
// This file contains all the functions of the deck class

#include "deck.h"
#include <algorithm> // for std::random_shuffle
using namespace std;

// constructor
// set head to NULL
deck::deck() : head(NULL) {}

// constructor
// set the node as same as the source
// input: a node objec
deck::deck(const node &source) {
  if (head) {
    delete head;
    head = NULL;
  }
  if (source.is_it_joker()) {
    const joker *joker_ptr = dynamic_cast<const joker *>(&source);
    if (joker_ptr)
      head = new joker(*joker_ptr);
  } else {
    const card *card_ptr = dynamic_cast<const card *>(&source);
    if (card_ptr)
      head = new card(*card_ptr);
  }
}

// desctrucor
// clear the linear linked list of pointer to node
deck::~deck() {
  node *temp = head;
  if (temp) {
    head = head->goto_next();
    delete temp;
    temp = head;
  }
}

// this function add a new node in the head of the deck,
// it receives a node by argument, and copy it to a new node,
// then add the new node to the begining of the deck( which is a
// linear linked list
// input: a pointer to a node
void deck::push(node *source) {
  if (source->is_it_joker()) {
    joker *joker_ptr = static_cast<joker *>(source);
    if (joker_ptr) {
      node *temp = new joker(*joker_ptr);
      temp->set_next(head);
      head = temp;
    }
  } else {
    card *card_ptr = static_cast<card *>(source);
    if (card_ptr) {
      node *temp = new card(*card_ptr);
      temp->set_next(head);
      head = temp;
    }
  }
}

// this function creates a set of poker, which contains 52 cards
// from 1 to 13 repeating 4 times.
// it create a array with all the value firstly, shuffle the array,
// and add those value to the deck finally.
void deck::create_a_set_of_poker() {
  srand(time(0));
  int array[54];
  for (int i = 0; i < 52; ++i)
    array[i] = (i % 13) + 1;
  array[52] = 100;
  array[53] = 100;
  int random = rand();
  int index = random % 54;
  random_shuffle(array, array + 54);
  for (int i = 0; i < 54; ++i) {
    // add two jokers
    if (array[i] == 100) {
      joker *joker_ptr = new joker();
      node *temp = dynamic_cast<node *>(joker_ptr);
      push(temp);
    } else {
      card *card_ptr = new card(array[i]);
      node *temp = dynamic_cast<node *>(card_ptr);
      push(temp);
    }
  }
}

// this fucntion pops the head node of the deck,
// and returns the deleted node
// output: a pointer to a card which is removed from the head of the deck
node *deck::pop() {
  if (head) {
    node *temp = dynamic_cast<node *>(head);
    node *current = head;
    head = head->goto_next();
    delete current;
    return temp;

  } else
    return NULL;
}

// return the value of the pointer to head,
// output: the value of the hea
int deck::get_head_value() {
  if (head)
    return head->get_value();
}

// this wrapper fucntion displays all the values of nodes in the deck
// by invoking another function
void deck::display() { display(head); }

// this function displays the values of nodes in the deck
// by calling itself recursively.
// input: a pointer to the head of the deck
////output: display the value of cards in the dec
void deck::display(node *head) {
  if (!head)
    return;
  int i = head->get_value();
  if (i == 100)
    cout << "joker"
         << " ";
  else
    cout << i << " ";
  display(head->goto_next());
}
