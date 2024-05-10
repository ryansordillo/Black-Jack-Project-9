#include "bet.h"
/**
 * Default constructor for bet class, initializes all atributes to 0
*/
Bet::Bet() {
    _current_bet = 0;
    _total_earnings = 0;
    _starting_amount = 0;    
}
/**
 * @param amount input amount that will be bet
 * Parameterized constructor that sets the amount equal to attribute of current bet
*/
void Bet::place_bet(int amount) {
    _current_bet = amount;
}
/**
* Gets the current bet
*/
int Bet::get_bet() {
    return _current_bet;
}
/**
* Gets total earnings
*/
int Bet::get_total_earnings() {
    return _total_earnings;
}
/**
* Gets final amount in relation to the input file
*/
int Bet::get_final_amount() {
    return _final_amount;
}
/**
* Reads the money from the file and initializes final amount to starting amount
*/
void Bet::read_starting_money(){
    string file_name = "money.txt";
    ifstream the_file(file_name);
    the_file >> _starting_amount;
    the_file.close();
    _final_amount = _starting_amount;
}
/**
* Prompts the user to enter a bet and uses that amount to place the bet by calling place_bet
*/
void Bet::prompt_bet() {
    cout << "Enter bet amount (0 to quit): ";
    int amount;
    cin >> amount;
    place_bet(amount);
}
/**
 * Correctly adds subtracts or does nothing to the total earnings based on outcome of the round
 * @param outcome outcome of the game, 1 = player win, -1 = dealer win, 0 = tie
*/
void Bet::update_earnings(int outcome) {
    if (outcome == 1) 
        _total_earnings += _current_bet;
    else if (outcome == -1)
        _total_earnings = _total_earnings - _current_bet;
    else
        _total_earnings = _total_earnings;
}
/**
* @return true if current bet doesn't equal 0, false if bet is 0
*/
bool Bet::is_active() {
    if (_current_bet != 0)
        return true;
    return false;
}
/**
* calculates final amount of money user has and writes it back into the file
*/
void Bet::write_money() {
    _final_amount += _total_earnings;
    string file_name = "money.txt";
    ofstream the_file(file_name);
    the_file << _final_amount << endl;
    the_file.close();    
}

