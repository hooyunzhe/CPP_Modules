#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	cout << "WrongCat default constructor called\n";
	this->_type = "WrongCat";
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->_brain->ideas[i] = "A WrongCat's idea " + std::to_string(i);
	}
}

WrongCat::WrongCat(const WrongCat &wrongcat_var) {
	cout << "WrongCat copy constructor called\n";
	*this = wrongcat_var;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called\n";
	delete this->_brain;
}

WrongCat	&WrongCat::operator = (const WrongCat &wrongcat_var) {
	cout << "WrongCat copy assignment operator called\n";
	this->_type = wrongcat_var._type;
	*(this->_brain) = *(wrongcat_var._brain);
	return (*this);
}

void	WrongCat::makeSound(void) const {
	cout << "Wrong Meow!\n";
}

Brain	*WrongCat::getBrain(void) const {
	return (this->_brain);
}
