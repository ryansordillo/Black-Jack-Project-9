/**
 * @file black_jack.cpp
 * @author Sophia Rodham and Ryan Sordillo
 * @brief This code simulates a game of Black Jack that will deal starting cards and take user input
 * to play the game. The user will be competing against a "dealer" and will be able to bet money.
 * @date April 25, 2024
 */
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include "stack.cc"
#include "card.cc"
#include "deck.cc"
#include "player.cc"
#include "bet.cc"

using namespace std;

int main() {
   Shoe shoe;
   Player player(shoe);
   Bet bet;
   bet.read_starting_money();
   bet.prompt_bet();
   cout << "Bet placed: $" << bet.get_bet() << endl;
   while (bet.get_bet() != 0) {
      player.moves();
      int outcome = player.check_winner(player.player_value, player.dealer_value);
      if (outcome != 0)
         bet.update_earnings(outcome);
      cout << "Current earnings: " << bet.get_total_earnings() << endl;
      bet.prompt_bet();
   }
   bet.write_money();
   cout << "Game over. Remaining money: " << bet.get_final_amount() << endl;
}


