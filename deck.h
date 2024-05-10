#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Deck {
public:
    Stack<Card> deck;
    vector<Card> cards;
    void initialize_deck();
    void shuffle_cards();
    void assemble_deck();
    void print_deck();
private:
    vector<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", \
                                                        "10", "Jack", "Queen", "King", "Ace"};
};
class Shoe : public Deck {
public:
    Shoe();
    void refill_shoe();
};

#endif // DECK_H
