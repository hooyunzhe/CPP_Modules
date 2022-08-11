#include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {
	cout << "Cure constructor called\n";
}

Cure::Cure(const Cure &cure_var) : AMateria(cure_var._type) {
	cout << "Cure copy constructor called\n";
}

Cure::~Cure() {
	cout << "Cure destructor called\n";
}

Cure	&Cure::operator = (const Cure &cure_var) {
	cout << "Cure copy assignment operator called\n";
	this->_type = cure_var._type;
	return (*this);
}

AMateria	*Cure::clone(void) const {
	return (new Cure());
}

void	Cure::use(ICharacter &target) {
	cout << "* heals " << target.getName() << "'s wounds *\n";
}