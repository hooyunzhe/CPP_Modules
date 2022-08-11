#include "FragTrap.hpp"

FragTrap::FragTrap(string name) : ClapTrap(name) {
	cout << "FragTrap constructor called\n";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
};

FragTrap::FragTrap(const FragTrap &fragtrap_var) : ClapTrap(fragtrap_var._name) {
	cout << "FragTrap copy constructor called\n";
	*this = fragtrap_var;
};

FragTrap::~FragTrap() {
	cout << "FragTrap destructor called\n";	
};

FragTrap	&FragTrap::operator = (const FragTrap &fragtrap_var) {
	cout << "FragTrap copy assignment operator called\n";
	this->_name = fragtrap_var._name;
	this->_hit_points = fragtrap_var._hit_points;
	this->_energy_points = fragtrap_var._energy_points;
	this->_attack_damage = fragtrap_var._attack_damage;
	return (*this);
};

void	FragTrap::highFivesGuys(void) {
	cout << "FragTrap " << this->_name << " says \"High five?\"\n";
};