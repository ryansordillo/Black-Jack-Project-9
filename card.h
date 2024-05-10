#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Card {
private:
    string _suit;
    string _rank;
public:
    Card();
    Card(string suit, string rank);
    string get_suit() const;
    string get_rank() const;
};

#endif // CARD_H