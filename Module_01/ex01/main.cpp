#include "Zombie.hpp"

int	main(void) {
	int		amount;
	Zombie	*horde;

	amount = 5;
	horde = zombieHorde(amount, "Horde Zomb");
	for (int i = 0; i < amount; i++) {
		horde[i].annouce();
	}
	delete[] horde;
}