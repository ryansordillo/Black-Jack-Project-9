#include "card.h"

/**
 * Default constructor for card class, initializes suit and rank to empty strings
*/
Card::Card() {
    _suit = "";
    _rank = "";
}
/**
 * Parameterized Constructor that sets attributes to suit and rank
 * @param suit string of the suit name
 * @param rank string of the card rank
*/
Card::Card(string suit, string rank) {
    _suit = suit;
    _rank = rank;
}
/**
 * gets the suit of the card
 * @return cards suit as a string
*/
string Card::get_suit() const {
    return _suit;
}
/**
 * gets the rank of the card
 * @return cards rank as a string
*/
string Card::get_rank() const {
    return _rank;
}
