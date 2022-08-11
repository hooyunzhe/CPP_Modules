#include "Dog.hpp"

Dog::Dog() : AAnimal() {
	cout << "Dog default constructor called\n";
	this->_type = "Dog";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_brain->ideas[i] = "A dog's idea " + std::to_string(i);
	}
}

Dog::Dog(const Dog &dog_var) {
	cout << "Dog copy constructor called\n";
	*this = dog_var;
}

Dog::~Dog() {
	cout << "Dog destructor called\n";
	delete this->_brain;
}

Dog	&Dog::operator = (const Dog &dog_var) {
	cout << "Dog copy assignment operator called\n";
	this->_type = dog_var.getType();
	*(this->_brain) = *(dog_var._brain);
	return (*this);
}

void	Dog::makeSound(void) const {
	cout << "Bark!\n";
}

Brain	*Dog::getBrain(void) const {
	return (this->_brain);
}
