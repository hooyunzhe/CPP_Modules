#include "ClapTrap.hpp"

ClapTrap::ClapTrap(string name) {
	cout << "Default constructor called\n";
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
};

ClapTrap::ClapTrap(const ClapTrap &claptrap_var) {
	cout << "Copy constructor called\n";
	*this = claptrap_var;
};

ClapTrap::~ClapTrap() {
	cout << "Destructor called\n";	
};

ClapTrap	&ClapTrap::operator = (const ClapTrap &claptrap_var) {
	cout << "Copy assignment operator called\n";
	this->_name = claptrap_var._name;
	this->_hit_points = claptrap_var._hit_points;
	this->_energy_points = claptrap_var._energy_points;
	this->_attack_damage = claptrap_var._attack_damage;
	return (*this);
};

void	ClapTrap::attack(const string &target) {
	if (this->_energy_points > 0) {
		cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!\n";
		this->_energy_points--;
	}
	else {
		cout << "ClapTrap " << this->_name << " doesn't have enough energy left...\n";
	}
};

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points > 0) {
		cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!\n";
		this->_hit_points -= amount;
	}
	else {
		cout << "ClapTrap " << this->_name << " doesn't have enough hit points left...\n";
	}
};

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points > 0) {
		cout << "ClapTrap " << this->_name << " repairs itself, recovering " << amount << " hit points!\n";
		this->_hit_points += amount;
		this->_energy_points--;
	}
	else {
		cout << "ClapTrap " << this->_name << " doesn't have enough energy left...\n";
	}
};