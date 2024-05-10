#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ncurses.h>
#include <ctime>
#include "deck.h"
#include "bet.h"

using namespace std;

class Player {
protected:
    Shoe shoe;
public:
    Player();
    Player(Shoe & s);
    void clear_hands();
    void deal_hand();
    void get_values();
    void moves();
    bool can_split();
    void hit();
    void stand(Player & dealer);
    int value_of_cards(vector<string> hand);
    void initialize_ncurses();
    void create_window(WINDOW *&win);
    void print_options(WINDOW *win, const string choices[], int highlight, int size);
    char selected_move(int highlight);
    char option_menu();
    void delay(int seconds);
    int check_winner(int player_value, int dealer_value);
    bool game_status = true;
    vector<string> player_hand;
    vector<string> dealer_hand;
    int player_value;
    int dealer_value;
    string hidden_card_rank;
    int _result;
};

ostream & operator<<(ostream & out, const Card & card);

class Dealer : public Player {
public:
    Dealer();
    Dealer(Shoe & s);
};

#endif // PLAYER_H
