#include "Card.h"


//the main method is to test the Cards of part 5;
int main() {

	//create aDeck and aHandCard
	Deck aDeck;
	//initial Deck to assign 30 cards, each type has 5 cards
	aDeck.initial_vec_deck();

	//print all cards of deck, it should has 30 cards, which has 5 types, each type has 5 cards.
	aDeck.print_vec_deck();
	
	HandCards aHandCard;
	//test the size of current deck
	aDeck.print_vec_deck_size();
	//using draw() to random a card from deck, then add in handcards
	cout << " test to assign 5 random cards into hand_cards \n"<<endl;
	for (int i = 0; i < 5; i++) {
		aHandCard.set_vec_hand_cards(aDeck.draw());
	}
	//print the current hand cards
	aHandCard.print_vec_hand_cards();
	
	//test the size of current deck
	aDeck.print_vec_deck_size();

	//test the play cards order of HandCard
	//traverse to set all HandCards will play
	cout<<YELLOW(" test to play all Cards of the HandCards...then remove it from HandCards and put the cards into vec_deck_cards \n")<<endl;
	int hand_size = aHandCard.get_vec_hand_cards()->size();
	for (int k = 0; k < hand_size; k++) {
		aHandCard.play(aHandCard.get_vec_hand_cards()->at(0), &aDeck);
	}//because the erase method of the vector will auto move the cards

	//print the vec_play_cards
	aHandCard.print_vec_play_cards();
	//print the current hand cards
	aHandCard.print_vec_hand_cards();

	//test the size of current deck
	aDeck.print_vec_deck_size();
	
}