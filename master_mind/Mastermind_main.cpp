#include "Mastermind.h"

int main(int argc, char const *argv[]) {
	vector<string> palette;
	palette.push_back("Red");
	palette.push_back("Blue");
	palette.push_back("Green");
	palette.push_back("White");
	palette.push_back("Yellow");
	palette.push_back("Orange");
	palette.push_back("Purple");
	palette.push_back("Turquoise");

	TextInput input(palette);
	TextOutput output(palette);
	Mastermind game(intput, output);

	return 0;
}