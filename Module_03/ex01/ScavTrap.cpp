#include "ScavTrap.hpp"

// ScavTrap::ScavTrap() {
// 	cout << "ScavTrap default constructor called\n";
// };

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	cout << "ScavTrap constructor called\n";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
};

ScavTrap::ScavTrap(const ScavTrap &scavtrap_var) : ClapTrap(scavtrap_var._name) {
	cout << "ScavTrap copy constructor called\n";
	*this = scavtrap_var;
};

ScavTrap::~ScavTrap() {
	cout << "ScavTrap destructor called\n";
};

ScavTrap	&ScavTrap::operator = (const ScavTrap &scavtrap_var) {
	cout << "ScavTrap copy assignment operator called\n";
	this->_name = scavtrap_var._name;
	this->_hit_points = scavtrap_var._hit_points;
	this->_energy_points = scavtrap_var._energy_points;
	this->_attack_damage = scavtrap_var._attack_damage;
	return (*this);
};

void	ScavTrap::attack(const string &target) {
	if (this->_energy_points > 0) {
		cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!\n";
		this->_energy_points--;
	}
	else {
		cout << "ScavTrap " << this->_name << " doesn't have enough energy left...\n";
	}
};

void	ScavTrap::guardGate() {
	cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!\n";
};