#include "Identify.hpp"

// Testing if identify correctly identifies the Base class type of a pointer to Base
int	main(void) {
	Base	*random;

	random = generate();
	identify(random);
	identify(*random);
}