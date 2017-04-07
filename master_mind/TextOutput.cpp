#include "TextOutput.h" 
#include <iostream>
using namespace std;

TextOutput::TextOutput(const vector<string>& colorNames) :
    _currentTurnNum(0), _lengthOfPattern(0), _maxNumberOfTurns(0), _colorOptions("") {
    for(vector<string>::const_iterator iter = colorNames.begin(); iter != colorNames.end(); ++iter)
    	_colorOptions.push_back((*iter)[0]);
}

void TextOutput::startGame(int lengthOfPattern, int maxNumberOfTurns) {
	_currentTurnNum = 0;
	_lengthOfPattern = lengthOfPattern;
	_maxNumberOfTurns = maxNumberOfTurns;
}

void TextOutput::displayTurn(const Pattern& guess, const Score& result) {
	_currentTurnNum++;
	cout << "On turn " << _currentTurnNum << " of " << _maxNumberOfTurns
	     << " guess " << _patternAsString(guess) << " scored "
	     << result.getNumBlack() << " black and " << result.getNumWhite()
	     << " white." << endl;
}

void TextOutput::announceVictory(const Pattern& secret) const {
	cout << endl;
	cout << "Congratulations, you won!" << endl;
	cout << "The secret was " << _patternAsString(secret) << endl;
}

void TextOutput::announceDefeat(const Pattern& secret) const {
	cout << endl;
	cout << "The secret was " << _patternAsString(secret) << endl;
	cout << "Good luck next time." << endl;
}

string TextOutput::_patternAsString(const Pattern& thePattern) const {
	string display;
	for(int i = 0; i < _lengthOfPattern; ++i) 
		display.push_back(_colorOptions[thePattern.getPegColor(i)]);
	return display;
}


