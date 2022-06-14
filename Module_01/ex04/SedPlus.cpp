#include "SedPlus.hpp"

SedPlus::SedPlus() {};
SedPlus::~SedPlus() {};

int		SedPlus::checkInput(int argc, char **argv) const {
	if (argc != 4) {
		cout << "usage: [filename] [string to find] [string to replace]\n";
		return (1);
	}
	if (argv[2] && !argv[2][0]) {
		cout << "error: string to find is empty\n";
		return (1);
	}
	return (0);
}

void	SedPlus::writePlus(ofstream &output_file, string oriString, string oldString, string newString) const {
	string	retString;
	
	for (size_t i = 0; i < oriString.length(); i++) {
		if (oriString.compare(i, oldString.length(), oldString, 0, oldString.length()) == 0) {
			output_file << newString;
			i += oldString.length() - 1;
		}
		else {
			output_file << oriString[i];
		}
	}
	output_file << endl;
}

void	SedPlus::sedPlus(string filename, string oldString, string newString) const {
	string		input;
	ifstream	input_file(filename);
	if (!input_file.is_open()) {
		cout << "error: can't open file, either file doesn't exist or no permission\n";
		return ;
	}
	ofstream	output_file(filename + ".replace");

	while (getline(input_file, input)) {
		writePlus(output_file, input, oldString, newString);
	}
	input_file.close();
	output_file.close();
}