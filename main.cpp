#include <iostream>
#include "hangman.h"

// Main function that runs the game

using namespace cppgames;

int main() {
    // Create a Hangman object with the word "hangman" and 10 guesses
    Hangman game("testgame", 10);
    // Play rounds of the game until it's over
    while (!game.IsGameOver()) {
        game.PlayRound();
    }
    // Print the final state of the game
    game.PrintFinalState();

    return 0;
}