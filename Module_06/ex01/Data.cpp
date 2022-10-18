#include "Data.hpp"

Data::Data(string var) : _var(var) {
	cout << GREEN "Data constructor called\n" RESET;
}

Data::Data(const Data &data_var) {
	cout << BLUE "Data copy constructor called\n" RESET;
	*this = data_var;
}

Data::~Data() {
	cout << RED "Data destructor called\n" RESET;
}

Data	&Data::operator = (const Data &data_var) {
	cout << CYAN "Data copy assignment operator called\n" RESET;
	this->_var = data_var._var;
	return (*this);
}

string	Data::getVar(void) const {
	return (this->_var);
}