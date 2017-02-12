#Object Oriented Programming
For this programs you will be applying OO techniques to creating a game. You will be creating a version of the card game WAR as described below with specific rules with a twist. Depending on the level of player (age for example), a variation is added called “Automatic” War where 2’s have special meaning and for advanced players, there is a version that adds spies (jokers). These versions will come into play for the second phase of the assignment with the user of dynamic binding. 

##The Overall Rules:
1. Start with a 52 card deck plus 2 jokers (called spys)2. There may be 2 or more players2. The deck is split randomly among each player; if there are any left over cards after dividing up the cards they become the property of the winner of the first war (they are the “spoils” of the first war!). 
3. These cards create each player’s “downstack”
4. When the game begins, the top card is “revealed the” for a “battle” and higher card wins. The cards go to the bottom of the winner’s downstack.  * If a Joker is revealed, it means that it has lost its advantage as a spy and is an automatic loss for that player’s turn.
  2. If a 2 is revealed (the lowest possible), it triggers an “Automatic” war.
  3. If there is a tie (or a 2), then a war takes place. Each player that had the same ranked card plays 4 cards where only the last one is “revealed” for “battle”. Again, the higher card wins and the cards to the bottom of the winner’s downstack. If there is a tie again, the process continues.
  4. There is one exception. When in a “war”, if one of the 3 down cards (that are not revealed) is a joker (a spy) then there is an automatic win for the player who had the joker. Think of this as you had a spy in the war and they caused a win!
  5. If there are two jokers in different player’s down cards (that are not revealed) in a war – then the war is over and no one wins. Everyone gets their cards back, at the bottom of their corresponding downstacks.5. If a player is out of cards, they may play their last available card up during a war.6. A player that is out of cards triggers the end of the game. The player with the most cards wins.
##In Two Stages:
For the first phase of the project (Program #1), your goal will be to establish the classes that are needed (minimum of 5) and build single inheritance hierarchies (required). It IS expected that the code will compile and that a player can get cards and start the process of playing. You will need classes such as card, deck, and player to start with. All of the rules do not yet need to be implemented for the first stage. But it is expected that **recursion** will be used in your design.
In the second phase of the project (Program #2), we will be applying dynamic binding where there will be multiple types of players. Depending on the level of player, the game will take on different rules (causing Automatic war when a 2 is played or having spies with Jokers). By the second phase, you need to support multiple players and all of the above mentioned rules.Part of each stage will be to apply a data structure to part of the problem. You will need data structures to manage each player’s downstack and the cards being played during a war. You must implement two data structures for Program #1 to support two of these concepts and the remaining in Program #2. Here are the required data structures with examples of how they might be used (others may be substituted with authorization from your Instructor):

1. A **circular linked list of arrays**; every element of the array should be a “card” (suggestion: for the downstack)2. An **array of linear linked lists**; (suggestion: for the war, where each element of the array corresponds to a different player’s cards and the LLL represents the list of cards in battle)3. A **graph implemented using an adjacency list** (suggestion: to manage the game; store pointers to base class objects for the players when using dynamic binding ). Use recursion.
In stage #2, **dynamic binding** is required with the use of 1 base class using virtual functions and 2 or more derived classes from it. At least one function must be pure virtual so that you experience abstract base classes in your design.
Implementation of the data structures requires full support of insert, removal, display, retrieval, and remove-all. If you get approval to use a different data structure from the list made available, then make sure it is clear to the grader what your selection is and why you have made that selection in your design write-up.
