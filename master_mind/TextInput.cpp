#include "TextInput.h"
#include <iostream>
#include <sstream>
using namespace std;

TextInput::TextInput(const vector<string>& colorNames) :
    _lengthOfPattern(0), _numColorsInUse(0), _palette("") {
    for(vector<string>::const_iterator iter = colorNames.begin(); iter != colorNames.end(); ++iter)
    	_palette.push_back((*iter)[0]);
}

int TextInput::_readInt(const string& prompt, int small, int large) const {
	string buffer;
	int answer = small - 1;     // intentionally invalid
	while (answer < small || answer > large) {
		cout << prompt << " (from " << small << " to " << large << ")? ";
		cin >> buffer;
		stringstream converter;
		converter << buffer;
		converter >> answer;
		if (!converter.fail()) {
			if (answer < small || answer > large) 
				cout << "Integer must be from " << small << " to " << large << "." << endl;
		}
		else {
			cout << "That is not a valid integer." << endl;
		}
	}
	return answer;
}

int TextInput::queryLengthOfPattern() {
	_lengthOfPattern = _readInt("How many pegs are in the secret", 1, 10);
	return _lengthOfPattern;
}

int TextInput::queryNumberOfColors() {
	_numColorsInUse = _readInt("How many colors are available", 2, _palette.size());
	return _numColorsInUse;
}

int TextInput::queryNumberOfTurns() const {
	return _readInt("How many turns are allowed", 1, 20);
}

bool TextInput::queryNewGame() const {
	cout << endl;
	cout << "Would you like to play again? " << endl;
	string answer;
	cin >> answer;
	return (answer == "y" || answer == "Y" || answer == "yes" 
		    || answer == "YES" || answer == "Yes");
}

Pattern TextInput::enterGuess() const {
	Pattern pattern(_lengthOfPattern);
	string currentPalette = _palette.substr(0, _numColorsInUse);
	string patternString;
	bool validPattern = false;
	while (!validPattern) {
		cout << endl;
		cout << "Enter a guess (colors are ";
		cout << _palette.substr(0,_numColorsInUse) << "): ";
		cin >> patternString;

		validPattern = true;
		if(patternString.size() != _lengthOfPattern) {
			cout << "The pattern must have " << _lengthOfPattern << " pegs" << endl;
			validPattern = false;
		} else {
			for(int i = 0; i < _lengthOfPattern; ++i) 
				if (currentPalette.find(toupper(patternString[i])) > _lengthOfPattern)
					validPattern = false;
			if(!validPattern) 
				cout << "The color options are " << currentPalette << endl;
		}

		if(validPattern) 
			for(int i = 0; i < _lengthOfPattern; ++i) 
				pattern.setPegColor(i, _palette.find(toupper(patternString[i])));
	}
	return pattern;
}

