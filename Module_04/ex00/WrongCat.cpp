#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	cout << "WrongCat default constructor called\n";
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongcat_var) {
	cout << "WrongCat copy constructor called\n";
	*this = wrongcat_var;
}

WrongCat::~WrongCat() {
	cout << "WrongCat destructor called\n";
}

WrongCat	&WrongCat::operator = (const WrongCat &wrongcat_var) {
	cout << "WrongCat copy assignment operator called\n";
	this->_type = wrongcat_var._type;
	return (*this);
}

void	WrongCat::makeSound(void) const {
	cout << "Wrong Meow!\n";
}
