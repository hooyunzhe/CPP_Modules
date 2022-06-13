#include "Zombie.hpp"

using std::string;

Zombie	*newZombie(string name) {
	Zombie	*newZomb;

	newZomb = new Zombie();
	newZomb->setName(name);
	return (newZomb);
}