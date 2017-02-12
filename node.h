// Jiaqi Luo, 21/7, CS202, hw2, node.h
// this file contaims the deleration of the class card and the class node

#include <cctype>
#include <cstring>
#include <iostream>

// the node class, which is the base class
class node {
public:
  // constructor
  node();
  // constructor
  // input: a bool value to determine is it a joker
  // example: true
  node(const bool is_joker);
  // constructor
  // input: a node objec
  node(const node &source);
  // destructor
  virtual ~node();
  // set the next pointer of the current node
  // input: a pointer to a node
  void set_next(node *next);
  // return the next pointer inside the current node
  // output: a pointer to a node which is the next pointer inside the current
  // node
  node *goto_next();
  // a virtual function, which returns the value of the current card or joker
  // deponding on the data type of the current node
  // output:the value of the card
  virtual int get_value() const = 0;
  // a virtual function, which sets the value of the current card or joker
  // input: the value you want for the card
  virtual void set_value(int data) = 0;
  // return ture if the current node is a joker, else return false
  bool is_it_joker() const;

protected:
  node *next;    // pointer to next nodeu
  bool is_joker; // a bool value, it is true if the current ndoe is a joker,
                 // else it is false
};

// the card class which inherts the node class
class card : public node {
public:
  // constructor
  card();
  // constructor
  // input: the value of the current card
  // example: 3
  card(const int value);
  // constructor
  // input: a card object
  card(const card &source);
  // destructor
  ~card();
  // return the value of the current card
  // output:the value of the card
  int get_value() const;
  // set the value of the current card
  // input: the value you want for the card
  void set_value(int data);

protected:
  int value; // the value of the card
};

// the joker class which inherts the node class
class joker : public node {
public:
  // constructor
  joker();
  // constructor
  // input: the value of the current joker
  // example: 100
  joker(const int data);
  // constructor
  // input: a card object
  joker(const joker &source);
  // destructor
  ~joker();
  // return the value of the current joker
  // output:the value of the joker
  int get_value() const;
  // set the value of the current joker
  // input: the value you want for the joker
  void set_value(int data);

protected:
  int value; // the value of the joker
};
