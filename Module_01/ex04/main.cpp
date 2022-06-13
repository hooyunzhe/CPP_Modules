#include "SedPlus.hpp"

int	main(int argc, char **argv) {
	SedPlus	sp;
	
	if (sp.checkInput(argc, argv) == 1) {
		return (1);
	}
	sp.sedPlus(argv[1], argv[2], argv[3]);
	return (0);
}