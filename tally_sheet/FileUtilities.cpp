#include "FileUtilities.h"
#include <fstream>
#include <iostream>
using namespace std;

void openFileReadRobust(ifstream& source) {
	source.close();       // disregard any previous usage of the stream
	while (!source.is_open()) {
		string filename;
		cout << "What is the filename? ";
		getline(cin, filename);
		source.open(filename.c_str());
		if (!source.is_open())
			cout << "Sorry. Unable to open file " << filename << endl;
	}
}

void openFileWriteRobust(ofstream& fout, const string& defaultName) {
	cout << "Within openFileWriteRobust" << endl;
	fout.close();
	while (!fout.is_open()) {
		string filename;
		cout << "What should the output to be named [" << defaultName << "]? ";
		getline(cin, filename);
		if (filename.size() == 0)
			filename = defaultName;
		fout.open(filename.c_str());
		if (!fout.is_open())
			cout << "Sorry. Unable to write to file " << filename << endl;
	}
}