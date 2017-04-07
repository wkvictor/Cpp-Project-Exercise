#include "FileUtilities.h"
#include "TallySheet.h"
#include <cctype>      // provide isalpha and toupper
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream source;
	ofstream tallyfile;

	TallySheet<char> sheet('A','Z');
	cout << "This program counts the frequency of letters." << endl;
	cout << "Only alphabetical characters are considered." << endl << endl;
	
	openFileReadRobust(source);
	while (!source.eof()) {
		char character;
		source >> character;
		if (isalpha(character))
			sheet.increment(toupper(character));
	}
	source.close();

	openFileWriteRobust(tallyfile, "frequency.txt");
	sheet.writeTable(tallyfile);
	tallyfile.close();

	return 0;
}