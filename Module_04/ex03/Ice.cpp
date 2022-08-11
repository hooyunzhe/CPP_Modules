#include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {
	cout << "Ice constructor called\n";
}

Ice::Ice(const Ice &ice_var) : AMateria(ice_var._type) {
	cout << "Ice copy constructor called\n";
}

Ice::~Ice() {
	cout << "Ice destructor called\n";
}

Ice	&Ice::operator = (const Ice &ice_var) {
	cout << "Ice copy assignment operator called\n";
	this->_type = ice_var._type;
	return (*this);
}

AMateria	*Ice::clone(void) const {
	return (new Ice());
}

void	Ice::use(ICharacter &target) {
	cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
