#ifndef CPPGAMES_HANGMAN_H_
#define CPPGAMES_HANGMAN_H_

#include <iostream>

namespace cppgames
{
	class Hangman
	{
		// Private data members
		std::string m_word;
		std::string m_progress;
		int m_remainingguesses;

		void UpdateProgress(char letter);
		void PrintState() const;
		std::string replaceChar(std::string str, char ch1, char ch2);
	public:
		Hangman(const std::string& word, int guesses);
		void PlayRound();
		bool IsGameOver() const;
		void PrintFinalState() const;
	};
}

#endif