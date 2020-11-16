#pragma once
/*6 types of cards (spy, bomb, reinforcement, blockade, airlift and diplomacy),
*each type has 5 cards, so totally 30 cards in the initial deck.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> //for sort, union, intersection method
#include <stdlib.h> //for srand, rand
#include <time.h>//time
#include <iterator> 

//define some color styles for print
#define COLOR(msg, code) "\033[1;" #code "m" msg "\033[0m" 
#define RED(msg) COLOR(msg, 31)
#define GREEN(msg) COLOR(msg, 32)
#define YELLOW(msg) COLOR(msg, 33)

using namespace std;

class Card
{
public:
	Card();
	//virtual destructor 
	virtual ~Card();
	//copy constructor
	Card(const Card& c);
	//assignment operators
	Card& operator = (const Card& c);

	//initialize the type vec
	void initial_vec_type_card();

	//get pointer to the type vec
	vector<string>* get_ptr_type_arr();
	//for test to print vec_types_card
	void print_vec_types_card();

	//set card type id, from 0-5
	void set_card_type_id(int num);
	//get card type 
	string* get_card_type();



private:
	//the vector stores the 6 types of card, 0 is spy, 1->boomb, 2->reinforcement, 3->blockade, 4->airlift, 5->displomacy
	vector<string> vec_types_card = { "spy", "bomb", "reinforcement", "blockade", "airlift", "displomacy" };
	string* card_type;//for card type

};

//deck class inherit the card class
class Deck : public Card {

public:
	Deck();
	~Deck();
	//copy constructor
	Deck(const Deck& d);
	//assignment operators
	Deck& operator=(const Deck& d);

	//initial the deck vec, assign 30 cards in it, each type has 5 cards.
	void initial_vec_deck();

	//test to print the all card of initial vec_deck 
	void print_vec_deck();
	//print the size of vec_dec
	void print_vec_deck_size();

	//draw method is to allow a player to draw a card at random from the cards remaining in the deck
	//return a Card
	Card* draw();

	//the method is to return played cards into Deck_vec
	void add_card_to_deck_vec(Card* one_card);


private:
	vector<Card*> vec_deck; //store deck cards
	Card* ptr_card;//pointer to card
	Card* temp_card;//for draw and remove the element of vector
};

//HandCards class inherit  Card Class 
class HandCards : public Card {

public:
	HandCards();
	~HandCards();
	//copy constructor
	HandCards(const HandCards& h);
	//assignment operators
	HandCards& operator=(const HandCards& h);

	//set vec hand cards
	void set_vec_hand_cards(Card* a_card);
	//test to print the vec_hand_cards
	void print_vec_hand_cards();
	//test to print the vec_play_cards
	void print_vec_play_cards();

	//play() method that is called to play the card
	//creates an order and add it to the player's list, then return the card to the deck.
	void play(Card* a_card, Deck* a_Deck);

	//return a card to the deck cards, for play() method
	void return_played_card_to_deck(Deck* a_Deck);

	//get pointer to vec_hand_cards
	vector<Card*>* get_vec_hand_cards();
	//get pointer to vec_play_cards
	vector<Card*>* get_vec_play_cards();

	//remove the a played card from hand_cards, for play() method
	void remove_played_card_of_hand_cards(Card* r_card);

	//clear play_cards after player played cards
	void clear_play_cards();

private:
	vector<Card*> vec_hand_cards;//for store hand cards
	vector<Card*> vec_play_cards;//for store play cards

};
