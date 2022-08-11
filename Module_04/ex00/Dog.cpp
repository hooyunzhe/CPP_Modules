#include "Dog.hpp"

Dog::Dog() : Animal() {
	cout << "Dog default constructor called\n";
	this->_type = "Dog";
}

Dog::Dog(const Dog &dog_var) {
	cout << "Dog copy constructor called\n";
	*this = dog_var;
}

Dog::~Dog() {
	cout << "Dog destructor called\n";
}

Dog	&Dog::operator = (const Dog &dog_var) {
	cout << "Dog copy assignment operator called\n";
	this->_type = dog_var._type;
	return (*this);
}

void	Dog::makeSound(void) const {
	cout << "Bark!\n";
}
