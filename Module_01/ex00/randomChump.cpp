#include "Zombie.hpp"

using std::string;

void	randomChump(string name) {
	Zombie	chump;

	chump = Zombie();
	chump.setName(name);
	chump.annouce();
}