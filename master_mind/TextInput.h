#ifndef TEXTINPUT_H
#define TEXTINPUT_H

#include "Pattern.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * \brief Class for dealing with text-based input for the Mastermind game
 */
class TextInput {
private:
	int _lengthOfPattern;
	int _numColorsInUse;
	string _palette;

public:
	/**
	 * \brief Create a new text input instance.
	 *
	 * \param colorNames a list of strings (each color must start with a different letter)
	 */
	TextInput(const vector<string>& colorNames);

	/**
	 * \brief Ask the user how many pegs in the secret pattern
	 * 
	 * The length of the pattern is also stored internally
	 *
	 * \return the length of the pattern
	 */
	int queryLengthOfPattern();

	/**
	 * \brief Ask the user how many colors to use for secret pattern
	 *
	 * The number of colors is also stored internally.
	 *
	 * \return the number of colors
	 */
	int queryNumberOfColors();

	/**
	 * \brief Ask the user maximum number of guesses to be allowed
	 *
	 * \return the maximum number of guesses
	 */
	int queryNumberOfTurns() const;

	/**
	 * \brief Offer the user a new game.
	 * 
	 * \return true if accepted, false otherwise
	 */
	bool queryNewGame() const;

	/**
	 * \brief Get a guess from the user and return it as a Pattern instance
	 *
	 * \return the pattern entered
	 */
	Pattern enterGuess() const;

private:
	/**
	 * \brief Robustly prompt the user for an integer from small to large
	 */
	int _readInt(const string& prompt, int small, int large) const;
};

#endif