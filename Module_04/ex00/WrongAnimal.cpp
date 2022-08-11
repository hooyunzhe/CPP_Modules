#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal_var) {
	cout << "WrongAnimal copy constructor called\n";
	*this = wronganimal_var;
}

WrongAnimal::~WrongAnimal() {
	cout << "WrongAnimal destructor called\n";
}

WrongAnimal	&WrongAnimal::operator = (const WrongAnimal &wronganimal_var) {
	cout << "WrongAnimal copy assignment operator called\n";
	this->_type = wronganimal_var._type;
	return (*this);
}

string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	cout << "Wrong Animal sounds...\n";
}
