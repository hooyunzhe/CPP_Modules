#include "Cat.hpp"

Cat::Cat() : Animal() {
	cout << "Cat default constructor called\n";
	this->_type = "Cat";
}

Cat::Cat(const Cat &cat_var) {
	cout << "Cat copy constructor called\n";
	*this = cat_var;
}

Cat::~Cat() {
	cout << "Cat destructor called\n";
}

Cat	&Cat::operator = (const Cat &cat_var) {
	cout << "Cat copy assignment operator called\n";
	this->_type = cat_var._type;
	return (*this);
}

void	Cat::makeSound(void) const {
	cout << "Meow!\n";
}
