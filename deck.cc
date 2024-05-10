#include "deck.h"

const int SHOE_SIZE = 8;

/**
 * creates a deck of 52 cards and stores it in a vector of strings
*/
void Deck::initialize_deck() {
    for (int i = 0; i < suits.size(); i++) {
        for (int j = 0; j < ranks.size(); j++) {
            cards.push_back(Card(suits[i], ranks[j]));
        }
    }
}
/**
 * Shuffles the vector of cards giving us a random order
 * CITE: https://www.geeksforgeeks.org/how-to-shuffle-a-vector-in-cpp/
*/
void Deck::shuffle_cards() {
    random_device rd;
    mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
/**
 * Puts each element from the cards vector onto a stack of Card objects
*/
void Deck::assemble_deck() {
    for (int i = 0; i < cards.size(); i++) {
        deck.push(cards[i]);
    }
    cards.clear();
}
/**
 * displays the deck of cards
*/
void Deck::print_deck() {
    deck.display();
    cout << "Size: " << deck.size() << endl;
}
/**
 * Default Constructor for shoe subclass
 */
Shoe::Shoe() {
}
/**
 * Creates a black_jack shoe by making 8 decks and pushes them onto a stack 
 */
void Shoe::refill_shoe() {
    for (int i = 0; i < SHOE_SIZE; i++) {
        initialize_deck();
        shuffle_cards();
        assemble_deck();
    }
}
