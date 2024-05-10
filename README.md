# CS 102 Final Project

For this project, I am requiring a "Diary"; see the project for more details. I've included one example entry.

# Diary Entries

## April 23

Prof. Helmuth setup the repository:
- I created a .gitignore file, to make git not track unneeded files.
- I copied Prof. Strash's CMakeLists.txt file from last semester. You'll learn how to use this in lab this week.
- I made this readme!

## April 25

 - We selected the idea of the game Black Jack for our project.
 - Tenetively created a plan and discussed the logistics for our project

## April 27
 - After further discussing a plan, we want to try to use inheritance to make a Deck class with our card class inside of it. This may involve some trial and error however we believe it could be an efficient solution to our code.
 - We implemented the Deck and Card classes and wrote the constructor for the Card class.
 - We brain stormed possible opertors we will need in the deck class

## April 28
 - We implemented the initialize deck method that creates a deck of cards correctly
 - We wrote the print deck method to print the deck of cards to ensure it was created correctly and for future use
 - We also began to write the move method since this will help us understand what other methods we will need to implement for the game. 

## April 29
 - We modified our initialize deck method to create a deck of cards and store it in a vector of cards objects
 - Added a shuffle cards method that randomizes the order of the cards in the vector
 - Added an assemble deck method that pushes each card onto a stack of type cards creating a deck
 - Tried to make a multi-file project, but ran into some errors and was not quite completed

## April 30
 - We fixed our make file error and now everything compiles correctly
 - Added a shoe subclass of our deck class that makes a black jack shoe inlcuding 8 decks

## May 1
- We made a function to deal the hands of the user and the dealer.
- We moved our Deck and Shoe classes into .h and .cc files. 
 - Tried to make a multifile project, but ran into some errors and was not quite completed

## May 2
- We changed our shoe inheritance to a muti-deck call because it wasn't optimizing inheritance. 
- We created inheritance through a player class and dealer class because they will share a lot of code but differ through the actual gameplay. 

## May 3
- We tried different methods with our Shoe class however it would not function the same so we reverted it to a subclass.
- We implemented a way to print each hand with an operator overwrite.

## May 4
- We implemented a way for the player to hit and allow them to hit until they lose or they stand. 
- We implemented the stand for player as well and created the comparison for the dealer and player if the player stands. 

## May 5
- Fixed an error with the default constructor for Player class
- Adjusted the stand function to correctly add up card values and determine winnner, still getting error after game is finished
- Added a feature to hide the dealers second card to mimick real black jack, adjusted functions to account for this
- Added function to get a singular cards value

## May 6 
- We worked a lot on fixing errors within our code including memory and erros that were popping up as we were running the code.
- We implemented the ace logic to adjust the aces value to 1 if the hand goes over 21 upon dealing.
- We started on ncurses to try to implement a way for the user to select their move with a visual aspect.

## May 7
- We figured out one of the errors within our code to be within the stack destructor.
- We finished the ncurses for user input and used ctime like we learned in lab to create a delay in the display.

## May 8
- We implemented an operator overload to print out the cards in an easier to read way.
- We implemented a file input of how much money the user started with and write a file to reflect how much they have when they are finished. 
- We added all the style elements and completed our project!
