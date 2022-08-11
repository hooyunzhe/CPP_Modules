#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("A");

	a.attack("E");
	a.takeDamage(5);
	a.takeDamage(5);
	a.takeDamage(5);
	a.beRepaired(1);
	a.takeDamage(1);
	a.takeDamage(1);
	for (int i = 0; i < 8; i++) {
		a.attack("E" + std::to_string(i + 2));
	}
	a.beRepaired(10);
}