#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	cout << "AAnimal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &aanimal_var) {
	cout << "AAnimal copy constructor called\n";
	*this = aanimal_var;
}

AAnimal::~AAnimal() {
	cout << "AAnimal destructor called\n";
}

AAnimal	&AAnimal::operator = (const AAnimal &aanimal_var) {
	cout << "AAnimal copy assignment operator called\n";
	this->_type = aanimal_var._type;
	return (*this);
}

string	AAnimal::getType(void) const {
	return (this->_type);
}

void	AAnimal::makeSound(void) const {
	cout << "Animal sounds...\n";
}
