#include "HumanB.hpp"

HumanB::HumanB(string name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB() {};

void	HumanB::attack(void) const {
	cout << this->_name << " attacks with their " << this->_weapon->getType() << endl;
}

void	HumanB::setWeapon(Weapon *weapon) {
	this->_weapon = weapon;
}
