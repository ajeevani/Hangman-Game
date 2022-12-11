#include <iostream>
#include <vector>
#include "hangman.h"

using namespace std;

namespace cppgames
{
    // Method that updates the progress of the word being guessed
    void Hangman::UpdateProgress(char letter) {
        bool pass = false;
        for (int i = 0; i < m_word.length(); i++) {
            if (m_word[i] == letter) {
                m_progress[i] = letter;
                replaceChar(m_word, letter, '*');
            }
        }
    }

    // Method that prints the current state of the game
    void Hangman::PrintState() const {
        cout << "Word: " << m_progress << endl;
        cout << "Guesses remaining: " << m_remainingguesses << endl;
    }

    //Method that replaces matched letter(s)
    string Hangman::replaceChar(string str, char ch1, char ch2)
    {
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ch1)
                str[i] = ch2;
        }
        return str;

    }

    // Constructor that initializes the word to guess and number of remaining guesses
    Hangman::Hangman(const string& word, int guesses) : m_word(word), m_remainingguesses(guesses) 
    {
        for (int i = 0; i < word.length(); i++)
        {
            m_progress.push_back('*');
        }
    }

    // Method that plays a single round of the game
    void Hangman::PlayRound() {
        PrintState();
        cout << "Guess a letter: ";
        char letter;
        cin >> letter;
        if (m_word.find(letter) != string::npos) {
            cout << "Good guess!" << endl;
            UpdateProgress(letter);
        }
        else {
            cout << "Wrong guess!" << endl;
            m_remainingguesses--;
        }

    }

    // Method that checks if the game is over
    bool Hangman::IsGameOver() const {
        return m_remainingguesses == 0 || m_progress == m_word;
    }

    // Method that prints the final state of the game
    void Hangman::PrintFinalState() const {
        PrintState();
        if (m_remainingguesses == 0) {
            cout << "You lost! The word was: " << m_word << endl;
        }
        else {
            cout << "You won! The word was: " << m_word << endl;
        }
    }
}