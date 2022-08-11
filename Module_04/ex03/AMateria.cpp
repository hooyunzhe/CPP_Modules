#include "AMateria.hpp"

AMateria::AMateria(string const &type) : _type(type) {
	cout << "AMateria constructor called\n";
}

AMateria::AMateria(const AMateria &amateria_var) {
	cout << "AMateria copy constructor called\n";
	*this = amateria_var;
}

AMateria::~AMateria() {
	cout << "AMateria destructor called\n";
}

AMateria	&AMateria::operator = (const AMateria &amateria_var) {
	cout << "AMateria copy assignment operator called\n";
	this->_type = amateria_var._type;
	return (*this);
}

string const	&AMateria::getType(void) const {
	return (this->_type);	
}

void	AMateria::use(ICharacter &target) {
	cout << "* undefined AMateria " << target.getName() <<  " *\n";
}
