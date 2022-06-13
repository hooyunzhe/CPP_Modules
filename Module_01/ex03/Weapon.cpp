#include "Weapon.hpp"

Weapon::Weapon(string type) {
	this->_type = type;
}

Weapon::~Weapon() {}

void	Weapon::setType(string type) {
	this->_type = type;
}

const string	&Weapon::getType(void) const {
	return (this->_type);
}
