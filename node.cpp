// Jiaqi Luo, 21/7, CS202, hw2, node.cpp
// This file contains the functions of the card class and the node class

#include "node.h"
using namespace std;

// node class
// default constructor,
// set the next pointet to NULL, the is_joker to false
node::node() : next(NULL), is_joker(false) {}

// constructor
// set the next pointer to NULL,
// call the base class's constructor to set the is_joker vaule
// input: a bool value to determine is it a joker
// example: true
node::node(const bool value) : next(NULL), is_joker(value) {}

// constructor
// declear a new node with the same data as the source
// call the base class's constructor to set teh next pointer
// input: a node object
node::node(const node &source) : next(source.next) {}

// destructor
// delete the next pointer if it exists
node::~node() {
  if (next) {
    next = NULL;
  }
}

// return ture if the current node is a joker, else return false
bool node::is_it_joker() const { return is_joker; }

// this function set the pointer next in the current node,
// and the next pointer is the argument.
// input: a pointer to a node
void node::set_next(node *next) { this->next = next; }

// this fucntion returns the pointer next of the the current node
node *node::goto_next() { return next; }

// joker class
// default constructor
// set the value is 100,
// and call the base class's constructor to set the is_joker true
joker::joker() : value(100), node(true) {}

// constructor
// prompt the value of the curent joker
// and call the base class's constructor to set is_joker true
// input: the value of the joker you want
// example: 100
joker::joker(const int data) : value(data), node(true) {}

// cosntructor
// prompt a joker object and create a new joker with the same data
// call the base class's constructor to set is_joker true
// input: a joker object
joker::joker(const joker &source) : value(source.value), node(source) {}

// destructor, do nothing
joker::~joker() {}

// this fucntion returns the value of the current joker
// output: the value of the current joker
int joker::get_value() const { return value; }

// this function sets the value of the current joker,
// the valure is passed as the argument
// input: the value of the joker you want
void joker::set_value(int data) { value = data; }

// card class
// default constructor
// set the value is 0,
// and call the base class's constructor to set the is_joker false
card::card() : value(0), node() {}

// constructor
// prompt the value of the curent card
// and call the base class's constructor to set is_joker false
// input: the vaule of the card you want
// example: 4
card::card(const int value) : value(value), node() {}

// cosntructor
// prompt a card object and create a new card with the same data
// call the base class's constructor to set is_joker false
// input: a card objec
card::card(const card &source) : value(source.value), node(source) {}

// destructor, do nothing
card::~card() {}

// this fucntion returns the value of the current card
// output: the vaule of the current card
int card::get_value() const { return value; }

// this function sets the value of the current card,
// the valure is passed as the argument
// input: the vaue of the card you want
void card::set_value(int data) { value = data; }
