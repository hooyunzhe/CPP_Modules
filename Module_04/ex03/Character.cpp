#include "Character.hpp"

Character::Character(string name) : _name(name) {
	cout << "Character constructor called\n";
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &character_var) {
	cout << "Character copy constructor called\n";
	*this = character_var;
}

Character::~Character() {
	cout << "Character destructor called\n";
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
}

Character	&Character::operator = (const Character &character_var) {
	cout << "Character copy assignment operator called\n";
	this->_name = character_var._name;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
	}
	for (int i = 0; i < 4; i++) {
		if (character_var._inventory[i]) {
			this->_inventory[i] = character_var._inventory[i]->clone();
		}
	}
	return (*this);
}

string const	&Character::getName(void) const {
	return (this->_name);
}

void	Character::equip(AMateria *m) {
	if (!m) {
		cout << "Failed to equip Materia because it doesn't exist!\n";
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == m) {
			cout << "Failed to equip Materia of type " << m->getType() << " because it's already equipped!\n";
			return ;
		}
	}
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			this->_inventory[i] = m;
			cout << "Successfully equipped Materia of type " << m->getType() << " at index " << i << "!\n";
			return ;
		}
	}
	cout << "Failed to equip Materia of type " << m->getType() << " because " << this->_name << "'s inventory is full!\n";
}

void	Character::unequip(int idx) {
	if (idx <= 3) {
		if (this->_inventory[idx]) {
			cout << "Successfully unequipped Materia of type " << this->_inventory[idx]->getType() << " at index " << idx << "!\n";
			this->_inventory[idx] = NULL;
			return ;
		}
		cout << "Failed to unequip Materia at index " << idx << " because it doesn't exist!\n";
	}
	else {
		cout << "Failed to unequip Materia at index " << idx << " because index is out of range!\n";
	}
}

void	Character::use(int idx, ICharacter &target) {
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
		cout << "Successfully used Materia at index " << idx << "!\n";
	}
	else {
		cout << "Failed to use Materia at index " << idx << " because it doesn't exist!\n";
	}
}
