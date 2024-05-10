#ifndef BET_H
#define BET_H

#include <iostream>
#include <fstream>

using namespace std;

class Bet {
private:
    int _current_bet;
    int _total_earnings;
    int _starting_amount;
    int _final_amount;
public:
    Bet();
    void read_starting_money();
    void write_money();
    void place_bet(int amount);
    int get_bet();
    int get_final_amount();
    int get_total_earnings();
    void prompt_bet();
    void update_earnings(int outcome);
    bool is_active();
};

#endif // BET_H
