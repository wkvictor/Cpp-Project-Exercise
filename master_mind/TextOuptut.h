#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H

#include "Pattern.h"
#include "Score.h"
#include <string>
#include <vector>
using std::string;
using std::vector;

/**
 * \brief Provide text-based output for the Mastermind game.
 */
class TextOutput {
private:
	string _colorOptions;
	int _currentTurnNum;
	int _lengthOfPattern;
	int _maxNumberOfTurns;

public:
	/**
	 * \brief Construct a new TextOutput instance.
	 * 
	 * \param colorNames a sequence of strings (each color must start with a different letter)
	 */
	TextOutput(const vector<string>& colorNames);

	/**
	 * \brief Game is beginning with specified parameters
	 */
	void startGame(int lengthOfPattern, int maxNumberOfTurns);

	/**
	 * \brief Display recent guess Pattern and resulting Score to the screen.
	 */
	void displayTurn(const Pattern& guess, const Score& result);

    /**
     * \brief Inform the player that he/she has correctly matched the secret Pattern
     */
	void announceVictory(const Pattern& secret) const;

	/**
	 * \brief Inform the player that he/she has lost and reveal the secret Pattern.
	 */
	void announceDefeat(const Pattern& secret) const;

private:
	/**
	 * \brief Returns string representation of given Pattern using color shorthands.
	 */
	string _patternAsString(const Pattern& thePattern) const;
};

#endif