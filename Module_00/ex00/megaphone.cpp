#include <iostream>

using std::cout;
using std::endl;
using std::string;

string	trim_spaces(string str) {
	int	first = str.find_first_not_of(' ');
	int	last = str.find_last_not_of(' ');

	return (str.substr(first, last - first + 1));
}

string	string_to_uppercase(string str) {
	for (int i = 0; i < int(str.length()); i++) {
		str[i] -= (str[i] >= 'a' && str[i] <= 'z') ? 32 : 0;
	}
	return (str);
}

int	main(int argc, char **argv) {
	if (argc == 1) {
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else {
		for (int i = 1; i < argc; i++) {
			cout << string_to_uppercase(trim_spaces(argv[i]));
			if (i < argc - 1) {
				cout << ' ';
			}
		}
		cout << endl;
	}
}
