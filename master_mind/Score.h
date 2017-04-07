#ifndef SCORE_H
#define SCORE_H

/**
 * \brief A score for a single turn from game of Mastermind.
 *
 * A "black" component desigates the number of pegs that are 
 * exact matches for the answer. A "white" component counts
 * pegs that are correctly colored but not well positioned.
 */

class Score {
private:
	int _numBlack;
	int _numWhite;

public:
	/**
     * \brief Create score with given black and white components.
     * 
     * \param numBlack the black component of the score
     * \param numWhite the white component of the score
	 */
	Score(const int numBlack, const int numWhite) : 
	    _numBlack(numBlack), _numWhite(numWhite) { }

	/**
     * \brief Get the black component of the score.
     *
     * \return the number of pegs scored as black
	 */ 
	int getNumBlack() const {
		return _numBlack;           // in-lined implementation
	}

     /**
     * \brief Get the white component of the score.
     *
     * \return the number of pegs scored as white
	 */ 
	int getNumWhite() const {
		return _numWhite;           // in-lined implementation
	}

};

#endif