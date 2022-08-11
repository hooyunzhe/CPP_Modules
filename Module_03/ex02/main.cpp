#include "FragTrap.hpp"

int	main(void) {
	FragTrap	a("A");

	a.attack("E");
	a.takeDamage(50);
	a.takeDamage(50);
	a.takeDamage(50);
	a.beRepaired(10);
	a.takeDamage(10);
	a.takeDamage(10);
	for (int i = 0; i < 98; i++) {
		a.attack("E" + std::to_string(i + 2));
	}
	a.beRepaired(10);
	a.highFivesGuys();
}