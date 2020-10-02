#include "Card.h"


//the main method is to test the Cards of part 5;
int main() {

	//create aDeck and aHandCard
	Deck aDeck;
	//initial a deck
	aDeck.initial_vec_deck();

	//print all cards of deck, it should has 30 cards, which has 5 types, each type has 5 cards.
	//aDeck.print_vec_deck();

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
	cout<<" test to play all Cards of the HandCards...put the cards into vec_play_cards \n"<<endl;
	for (int k = 0; k < aHandCard.get_vec_hand_cards()->size(); k++) {
		aHandCard.play(aHandCard.get_vec_hand_cards()->at(k));
	}
	//print the vec_play_cards
	aHandCard.print_vec_play_cards();
	
	//test return played cards to deck
	aHandCard.return_played_card_to_deck(&aDeck);
	//test remove all played cards of hand cards
	aHandCard.remove_all_played_cards_of_hand_cards();
	//then clear the play cards of vec_play_cards. Notice: clean play_cards at end.
	aHandCard.clear_play_cards();

	//print the vec_play_cards
	aHandCard.print_vec_play_cards();
	//print the current hand cards
	aHandCard.print_vec_hand_cards();

	//test the size of current deck
	aDeck.print_vec_deck_size();
	
}