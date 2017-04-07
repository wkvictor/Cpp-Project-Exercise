#include "Mastermind.h"

Mastermind::Mastermind(TextInput& inputManager, TextOuput& outputManager) :
    _inputManager(inputManager), _outputManager(outputManager) {
    bool playAgain = true;
    while (playAgain) {
    	_runSingleGame();
    	playAgain = _inputManager.queryNewGame();
    }
}

void Mastermind::_runSingleGame() {
	// get parameters from the user
	int lengthOfPattern = _inputManager.queryLengthOfPattern();
	int numberOfColors = _inputManager.queryNumberOfColors();
	int maxNumberOfTurns = _inputManager.queryNumberOfTurns();
	_outputManager.startGame(lengthOfPattern, maxNumberOfTurns);

	// pick a new secret
	Pattern secret(lengthOfPattern);
	secret.randomize(numberOfColors);

	// start playing
	int round = 0;
	Pattern guess(lengthOfPattern);
	bool victory = false;
	while (round < maxNumberOfTurns && !victory) {
		round++;
		// enact a single turn
		guess = _inputManager.enterGuess();
		Score result = guess.compareTo(secret);
		_outputManager.displayTurn(guess, result);
		if(result.getNumBlack() == lengthOfPattern)
			victory = true;
	}

	if(victory)
		_outputManager.announceVictory(secret);
	else
		_outputManager.announceDefeat(secret);
}

