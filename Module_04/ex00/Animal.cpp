#include "Animal.hpp"

Animal::Animal() : _type("Animal") {
	cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &animal_var) {
	cout << "Animal copy constructor called\n";
	*this = animal_var;
}

Animal::~Animal() {
	cout << "Animal destructor called\n";
}

Animal	&Animal::operator = (const Animal &animal_var) {
	cout << "Animal copy assignment operator called\n";
	this->_type = animal_var._type;
	return (*this);
}

string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	cout << "Animal sounds...\n";
}
