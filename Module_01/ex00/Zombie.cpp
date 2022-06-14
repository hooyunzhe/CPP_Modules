#include "Zombie.hpp"

Zombie::Zombie() {};
Zombie::~Zombie() {
	cout << this->_name << endl;
};

void	Zombie::setName(string newName) {
	this->_name = newName;
}

string	Zombie::getName() const {
	return (this->_name);
}

void	Zombie::annouce(void) const {
	cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}