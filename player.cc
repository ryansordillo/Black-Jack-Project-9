#include "player.h"

const int BLACK_JACK = 21;

/**
 * Player Default Constructor
 * Initializes attributes
 */
Player::Player() {
    shoe = Shoe();
    player_value = 0;
    dealer_value = 0;
    game_status = true;
}
/**
 * Player Constructor
 * Initializes attributes
 */
Player::Player(Shoe & s) {
    shoe = Shoe();
    player_value = 0;
    dealer_value = 0;
    game_status = true;
}
/**
 * Dealer Default Constructor
 * Initializes attributes
 */
Dealer::Dealer() : Player() {
    dealer_value = 0;
}
/**
 * Dealer Constructor
 * Initializes attributes
 */
Dealer::Dealer(Shoe & s) : Player() {
    shoe = s;
}
/**
 * Finds the value of the hand of cards based on their rank
 * @param hand a vector of strings to check the value of
 * Source: //https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/# 
 * for string to integer
 * @return an integer value of the cards in the hand
 */
int Player::value_of_cards(vector<string> hand) {
    vector<int> hand_ints;
    int num_aces = 0;
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i] == "King" || hand[i] == "Queen" || hand[i] == "Jack" || hand[i] == "10")
            hand_ints.push_back(10);
        else if (hand[i] == "Ace") {
            hand_ints.push_back(11);
            num_aces++;
        }
        else if (hand[i] == "Hidden")
            hand_ints.push_back(0);
        else 
            hand_ints.push_back(stoi(hand[i]));
    }
    int total_value = 0;
    for (int i = 0; i < hand.size(); i++)
        total_value += hand_ints[i];
    while (total_value > BLACK_JACK && num_aces > 0) {
        total_value -= 10;
        num_aces--;
    }
    return total_value;
}
/**
 * Emptys the vectors of the hands of the player and dealer and resets the hand values to 0.
 */
void Player::clear_hands() {
    player_hand.clear();
    dealer_hand.clear();
    player_value, dealer_value = 0;
}
/**
 * Finds the value of the hand of cards based on their rank and prints each value.
 */
void Player::get_values() {
    player_value = value_of_cards(player_hand);
    dealer_value = value_of_cards(dealer_hand);
    cout << "Player value = " << player_value << " Dealer value : " << dealer_value << endl;
    if (player_value > BLACK_JACK)
        cout << "Lose" << endl;
}
/**
 * Deals two cards to both the user and the dealer (every other) and prints the 
 * card given. The second dealer card is hidden as it would be in a real
 * black jack game.
 */
void Player::deal_hand() {
    clear_hands();
    int card_size = 4;
    game_status = true;
    shoe.refill_shoe();
    for (int card_index = 0; card_index < card_size; card_index++) {
        Card dealt_card = shoe.deck.pop();
        if (card_index % 2 == 0) {
            player_hand.push_back(dealt_card.get_rank());
            cout << "Dealt to player: " << dealt_card << endl; 
        }
        else {
            if (card_index == 3) {
                dealer_hand.push_back("Hidden");
                cout << "Dealt to dealer: (Hidden)" << endl;
                hidden_card_rank = dealt_card.get_rank();
            }
            else {
                dealer_hand.push_back(dealt_card.get_rank());
                cout << "Dealt to dealer: " << dealt_card << endl;
            }
        }
    }
    get_values();
}
/**
 * If the player chooses to, a card will be added to their hand and the hand
 * will be checked to see if it busts.
*/
void Player::hit() {
    Card dealt_card = shoe.deck.pop();
    cout << "Dealt to player: " << dealt_card << endl;
    player_hand.push_back(dealt_card.get_rank());
    player_value = value_of_cards(player_hand); 
    cout << "Player value = " << player_value << endl << endl;
    if (player_value > BLACK_JACK) {
        cout << "Dealer wins" << endl;
        game_status = false; 
    }
}
/**
 * If the player chooses to stand, it implements the dealers rules to keep playing
 * then checks the hand values to see who wins
 * @param dealer a player object 
 */
void Player::stand(Player & dealer) {
    dealer_hand.back() = hidden_card_rank;
    cout << "Hidden Card Value: " << hidden_card_rank << endl;
    dealer_value = value_of_cards(dealer_hand);
    cout << "Initial Dealer Value: " << dealer_value << endl << endl;
    while (dealer_value < 17) {
        Card dealt_card = dealer.shoe.deck.pop();
        cout << "Dealt to dealer: " << dealt_card << endl;
        dealer_hand.push_back(dealt_card.get_rank());
        dealer_value = value_of_cards(dealer_hand);
        cout << endl << "Dealer value = " << dealer_value << endl << endl;
    }
    int result = check_winner(player_value, dealer_value);
    if (result == 1) 
        cout << "Player wins" << endl << endl;
    else if (result == -1) 
        cout << "Dealer wins" << endl << endl;
    else if (result == 0) 
        cout << "It's a tie" << endl << endl; 
}
/**
 * Compares the hands of the player and dealer to determine who the winner is
 * @param player_value the integer value of the players hand
 * @param dealer_value the integer value of the dealers hand
 * @return an integer that determines who wins
 */
int Player::check_winner(int player_value, int dealer_value) {
    if (player_value > BLACK_JACK || (dealer_value <= BLACK_JACK && dealer_value > player_value))
        return -1;
    else if (dealer_value > BLACK_JACK || player_value > dealer_value)
        return 1;
    else 
        return 0;
}
/**
 * Overwrites << to print out the cards in a specific format
 * @param out an ostream object 
 * @param card a card object
 * @return the overwritten operator
 */
ostream & operator<<(ostream & out, const Card & card) {
    if (card.get_rank() != "Hidden")
        out << card.get_rank() << " of " << card.get_suit();
    else
        out << "Hidden";
    return out;
}
/**
 * Clock to calculate the time delay of the ncurses window
 * @param seconds the amount of time to delay
 */
void Player::delay(int seconds) {
    clock_t start_time = clock();
    while ((clock() - start_time) / CLOCKS_PER_SEC < seconds) {
    }
}
/**
 * Initialize the ncurses screen
 */
void Player::initialize_ncurses() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
}
/**
 * Creates the ncurses window and sets the borders 
 * @param win a reference to the ncurses window
 */
void Player::create_window(WINDOW * & win) {
    int y_max, x_max;
    getmaxyx(stdscr, y_max, x_max);
    win = newwin(y_max / 2, x_max / 2, y_max / 4, x_max / 4);
    box(win, 0, 0);
    refresh();
    wrefresh(win);
    keypad(win, true);
}
/**
 * Prints the options of the user on the ncurses window
 * @param win a reference to the window
 * @param choices a string array of the user options
 * @param highlight the index of the highlighted choice
 * @param size the size of the choices
 */
void Player::print_options(WINDOW * win, const string choices[], int highlight, int size) {
    for (int i = 0; i < size; i++) {
        if (i == highlight)
            wattron(win, A_REVERSE);
        mvwprintw(win, i + 1, 1, "%s", choices[i].c_str());
        wattroff(win, A_REVERSE);
    }
}
/**
 * Returns the selected move based on the highlight index
 * @param highlight the index of the highlighted choice
 * @return the character of the highlighted choice
 */
char Player::selected_move(int highlight) {
    if (highlight == 0)
        return 'h';
    else
        return 's';
}
/**
 * Displays the option menu using ncurses
 * @return the character of the highlighted choice
 * CITE: https://www.youtube.com/watch?v=3YiPdibiQHA to help understand Ncurses and create the menu
 */
char Player::option_menu() {
    initialize_ncurses();
    WINDOW * win;
    create_window(win);
    int num_options = 2;
    string choices[num_options] = {"Hit", "Stand"};
    int choice;
    int highlight = 0;
    while (true) {
        print_options(win, choices, highlight, num_options);
        choice = wgetch(win);
        switch (choice) {
            case KEY_UP:
                highlight--;
                if (highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if (highlight == 2)
                    highlight = 1;
                break;
            default:
                break;
        }
        if (choice == 10)
            break;
    }
    endwin();
    return selected_move(highlight);
}
/**
 * controls the operation of the players moves and controls the menu screen
 */
void Player::moves() {
    deal_hand();
    delay(7); 
    char move = option_menu();
    while (move == 'h') {
        cout << endl;
        hit();
        if (game_status == false)
            break;
        delay(5); 
        move = option_menu();
    }
    if (move == 's') {
       Dealer dealer(shoe);
       stand(dealer);
    }
}
