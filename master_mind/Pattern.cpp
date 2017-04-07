#include "Pattern.h"
#include <set>
#include <algorithm>     // count
#include <stdlib.h>
using namespace std;

Pattern::Pattern(const int numPegs): _pegList(numPegs) {
	for(int i = 0; i < numPegs; ++i)
		_pegList[i] = 0;
}

int Pattern::len() const {
	return _pegList.size();
}

int Pattern::getPegColor(const int index) const {
	return _pegList[index];
}

void Pattern::setPegColor(const int index, const int colorId) {
	_pegList[index] = colorId;
}

Score Pattern::compareTo(const Pattern& otherPattern) const {
	// First calculate the black omponent of the score
	int black = 0;
	for(int i = 0; i < _pegList.size(); ++i)
		if (getPegColor(i) == otherPattern.getPegColor(i)) 
			black++;

	// The white component is a little more difficult to calculate
	// First find out the colors used in the current pattern
	set<int> colorsUsed;
	for(int i = 0; i < _pegList.size(); ++i)
		if (colorsUsed.count(_pegList[i]) == 0)
			colorsUsed.insert(_pegList[i]);

	// For each color used find the smaller number of time
	// it appears in each pattern and add them up
	int white = 0;
	set<int>::iterator colorIter;
	int color, count1, count2;
	for(colorIter = colorsUsed.begin(); colorIter != colorsUsed.end(); ++colorIter) {
		color = *colorIter;
		count1 = count(_pegList.begin(), _pegList.end(), color);
		count2 = count(otherPattern._pegList.begin(), otherPattern._pegList.end(), color);
		if (count1 < count2)
			white += count1;
		else
			white += count2;
	}
	white -= black;     // Do not count pegs that are paired up

    return Score(black,white);
}

void Pattern::randomize(const int numColors) {
	for(int i = 0; i < _pegList.size(); ++i) 
		setPegColor(i, rand() % numColors);
}




