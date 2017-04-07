#ifndef PATTERN_H
#define PATTERN_H

#include "Score.h"
#include <vector>

/**
 * \brief Class for storing a color pattern for Mastermind.
 */

class Pattern {
private:
	std::vector<int> _pegList;

public:
	/**
     * \brief Construct a new pattern.
     * 
     * Initially, the pattern consists of numPegs pegs, each set to color 0.
     * 
     * \param numPegs the length of the pattern
	 */
	Pattern(const int numPegs);

	/**
	 * \brief Return the length of the current pattern
	 *
	 * \return the length of the pattern
     */
	int len() const;

	/**
     * \brief Return the current color setting (an integer) of the specified peg.
     * 
     * \param index the index of the peg
     * \return the peg's color
	 */
	int getPegColor(const int index) const;

	/**
	 * \brief Set the color of a peg at the given index of the pattern.
	 *
	 * \param index the index of the peg
	 * \param colorID the desired color identifier (an integer)
	 */
	void setPegColor(const int index, const int color);

	/**
	 * \brief Compare the current pattern to another and calculate the score.
	 * 
	 * \param otherPattern the pattern to be compared to the current one
	 * \return a Score instance representing the result.
	 */
	Score compareTo(const Pattern& otherPattern) const;

	/**
	 * \brief Make a random pattern.
	 *
	 * \param numColors the maximum number of colors to use in the pattern
	 */
	void randomize(const int numColors);

};

#endif