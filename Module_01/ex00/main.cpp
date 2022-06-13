#include "Zombie.hpp"

int	main(void) {
	Zombie	zomb;
	Zombie	*newZomb;

	zomb = Zombie();
	zomb.setName("Zomb");
	zomb.annouce();
	newZomb = newZombie("New Zomb");
	newZomb->annouce();
	randomChump("Random Chump");
	delete newZomb;
}