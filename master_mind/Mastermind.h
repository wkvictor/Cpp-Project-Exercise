#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "TextInput.h"
#include "TextOutput.h"

/**
 * \brief Main class for the Mastermind game.
 */
class Mastermind{
private:
	TextInput& _inputManager;
	TextOutput& _outputManager;

public:
	/**
	 * \brief Create a new instance of the Mastermind game.
	 * 
	 * \param inputManager instance of class that gathers input from the user
	 * \param outputManager instance of class that displays output to the user
	 */
	Mastermind(TextInput& inputManager, TextOutput& outputManager);

private:
	/**
	 * \brief Play one game.
	 */
	void _runSingleGame();
};

#endif