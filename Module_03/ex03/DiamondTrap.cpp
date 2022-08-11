#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	cout << "DiamondTrap constructor called\n";
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	ClapTrap::_hit_points = FragTrap::_hit_points;
	ClapTrap::_energy_points = ScavTrap::_energy_points;
	ClapTrap::_attack_damage = FragTrap::_attack_damage;
};

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap_var) : ClapTrap(diamondtrap_var._name), ScavTrap(diamondtrap_var._name), FragTrap(diamondtrap_var._name) {
	cout << "DiamondTrap copy constructor called\n";
	*this = diamondtrap_var;
};

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap destructor called\n";
};

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &diamondtrap_var) {
	cout << "DiamondTrap copy assignment operator called\n";
	this->_name = diamondtrap_var._name;
	ClapTrap::_name = diamondtrap_var.ClapTrap::_name;
	ClapTrap::_hit_points = diamondtrap_var.FragTrap::_hit_points;
	ClapTrap::_energy_points = diamondtrap_var.ScavTrap::_energy_points;
	ClapTrap::_attack_damage = diamondtrap_var.FragTrap::_attack_damage;
	return (*this);
};

void	DiamondTrap::attack(const string &target) {
	ScavTrap::attack(target);
};

void	DiamondTrap::whoAmI(void) const {
	cout << "DiamondTrap's name: " << this->_name << endl;
	cout << "ClapTrap's name: " << ClapTrap::_name << endl;
};
