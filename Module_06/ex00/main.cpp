#include "Converter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		cout << RED "Error: please provide only 1 argument...\n" RESET;
	}
	else {
		Converter	scalars(argv[1]);

		scalars.checkType();
		scalars.toChar();
	}
}
