// Jiaqi Luo, 10/7, CS202, hw1, player.cpp
// this file contains the functions of the cll_node class and the players class

#include "player.h"
using namespace std;

// cll_node class
// constructor
// set current_index and top_index to 0,next to NULL
cll_node::cll_node() : current_index(0), top_index(0), next(NULL) {
  for (int i = 0; i < 54; ++i)
    hand[i] = NULL;
}

// constructor
// copy a cll_ndoe to the new one
////input: a cll_node objec
cll_node::cll_node(const cll_node &source)
    : current_index(source.current_index), top_index(source.top_index),
      next(source.next) {
  for (int i = 0; i < 54; ++i) {
    if (source.hand[i]) {
      if (hand[i]) {
        delete hand[i];
        hand[i] = NULL;
      }
      hand[i] = dynamic_cast<node *>(source.hand[i]);
    }
  }
}

// desctructor
// delete all the nodes in the array if exist
cll_node::~cll_node() {
  for (int i = 0; i < 54; ++i) {
    if (hand[i]) {
      delete hand[i];
      hand[i] = NULL;
    }
  }
  if (next)
    next = NULL;
}

// this function returns the next poitner in the current cll_node
cll_node *cll_node::goto_next() { return next; }

// this function adds a new card in the array which in the current cll_node
// and increase the num_of_cards by 1.
// it will check the data type of the source first,
// if it is joker, create a pointer to joker to carry the source,
// and add the copy to the hand
// if it is card, create a pointer to card to carry the source,
// and add the copy to the hand
void cll_node::add_card(node *source) {
  if (source->is_it_joker()) {
    const joker *joker_ptr = static_cast<const joker *>(source);
    hand[top_index] = new joker(*joker_ptr);
  } else {
    const card *card_ptr = static_cast<const card *>(source);
    hand[top_index] = new card(*card_ptr);
  }
  ++top_index;
}

// this function play a card by returning the card,
// and increase the top_index by 1
// it will check the data type of the node,
// and create a current pointer to copy the data,
// finally delete the original source,and reutrn the copy
// else return false
// output: a pointer to the origianl head node
node *cll_node::play_a_card() {
  if (top_index - current_index != 0) {
    node *temp = dynamic_cast<node *>(hand[current_index]);
    delete hand[current_index];
    hand[current_index] = NULL;
    ++current_index;
    return temp;
  } else
    return NULL;
}

// set the next pointer to cll_node in the linear linked list
// input: a pointer to next cll_nod
void cll_node::set_next(cll_node *target) { next = target; }

// this fucntion displays the number of nodes in a cll_node,
void cll_node::display() {
  cout << "has " << top_index - current_index << " cards: ";
  // if you want to display all the vales,
  // please remove the command mark.
  /*
  for(int i = current_index; i < top_index; ++ i)
  {
      int value = hand[i] -> get_value();
      if(value != 0)
      {
          if(value == 100)
              cout << "joker" << " ";
          else
              cout << value << " ";
      }
  }
  */
}

// check whether there is a joker in the array
// output: true if there is a joker, else return false
bool cll_node::check_joker() {
  if (top_index > 0) {
    for (int i = current_index; i < top_index; ++i) {
      if (hand[i]->get_value() == 100)
        return true;
    }
  } else
    return false;
}

// players class
// constructor
// set rear to NULL, num_of_player to 0
players::players() : rear(NULL), num_of_player(0) {}

// destructor
// delete all the cll_nodes if exist
players::~players() {
  if (rear) {
    cll_node *temp = rear->goto_next();
    rear->set_next(NULL);
    while (temp) {
      cll_node *current = temp->goto_next();
      delete temp;
      temp = current;
    }
  }
}

// this function add a new cll_node in the circular linked list
// the new cll_node is passed as the argument
// input: a pointer to a cll_node
void players::add(cll_node *new_player) {
  if (rear) {
    cll_node *temp = new cll_node(*new_player);
    if (num_of_player == 1) {
      rear->set_next(temp);
      temp->set_next(rear);
      ++num_of_player;
    } else {
      cll_node *head = rear->goto_next();
      rear->set_next(temp);
      temp->set_next(head);
      ++num_of_player;
    }
    return;
  } else {
    rear = new cll_node(*new_player);
    rear->set_next(NULL);
    ++num_of_player;
  }
}

// return the head in the CLL by argument
// return 0 if player1 doesn't have card
// return 1 if player2 doesn't have card
// return 2 if both doesn't have card
// return -1 if both have
// return 3 if the source is empty
int players::play_a_card(deck &a_deck) {
  bool player1_plays_a_card = true;
  bool player2_plays_a_card = true;
  if (rear) {
    node *source = rear->play_a_card();
    if (source)
      a_deck.push(source);
    else
      player1_plays_a_card = false;
  } else
    return 3;
  cll_node *temp = rear->goto_next();
  if (temp) {
    node *source2 = temp->play_a_card();
    if (source2)
      a_deck.push(source2);
    else
      player2_plays_a_card = false;
  }
  if (player1_plays_a_card == false && player2_plays_a_card == true)
    return 0;
  else if (player1_plays_a_card == true && player2_plays_a_card == false)
    return 1;
  else if (player1_plays_a_card == false && player2_plays_a_card == false)
    return 2;
  else
    return -1;
}

// check if there is a joker in the CLL
// there are two bool values inside the class,
// and both default is false,
// if one of them become true, then return true
// output:
// ture if there is a joker
// else fals
bool players::check_joker() {
  bool player1 = false;
  bool player2 = false;
  cll_node *temp = rear;
  if (temp)
    player1 = rear->check_joker();
  temp = temp->goto_next();
  if (temp)
    player2 = rear->check_joker();
  if (player1 == true && player2 == true)
    return true;
  else
    return false;
}

// add a new node to the head of a particular player's hand
// input: the pointer to soruce node, the index of the receiver
// 0 - player1
// 1 - player2
void players::add_card_to_a_player(node *source, int player_index) {
  if (player_index == 0)
    rear->add_card(source);
  else if (player_index == 1) {
    cll_node *temp = rear->goto_next();
    temp->add_card(source);
  }
}

// this function displays the cards of each player in the circular linked list
// by call conresponding functions
void players::display() {
  cll_node *temp = rear;
  for (int i = 0; i < num_of_player; ++i) {
    cout << "\n player #" << i + 1 << ": ";
    temp->display();
    temp = temp->goto_next();
  }
}
