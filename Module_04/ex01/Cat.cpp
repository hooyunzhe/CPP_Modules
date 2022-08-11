#include "Cat.hpp"

Cat::Cat() : Animal() {
	cout << "Cat default constructor called\n";
	this->_type = "Cat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_brain->ideas[i] = "A cat's idea " + std::to_string(i);
	}
}

Cat::Cat(const Cat &cat_var) {
	cout << "Cat copy constructor called\n";
	*this = cat_var;
}

Cat::~Cat() {
	cout << "Cat destructor called\n";
	delete this->_brain;
}

Cat	&Cat::operator = (const Cat &cat_var) {
	cout << "Cat copy assignment operator called\n";
	this->_type = cat_var._type;
	*(this->_brain) = *(cat_var._brain);
	return (*this);
}

void	Cat::makeSound(void) const {
	cout << "Meow!\n";
}

Brain	*Cat::getBrain(void) const {
	return (this->_brain);
}
