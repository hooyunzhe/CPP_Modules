#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon) : _name(name), _weapon(weapon) {};

HumanA::~HumanA() {};

void	HumanA::attack(void) const {
	cout << this->_name << " attacks with their " << this->_weapon.getType() << endl;
}