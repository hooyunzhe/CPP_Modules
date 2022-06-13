#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::~Zombie() {
	cout << name << endl;
};

void	Zombie::annouce(void) {
	cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(string newName) {
	name = newName;
}

string	Zombie::getName() {
	return (name);
}
