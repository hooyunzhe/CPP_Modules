#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed &fixed_var) {
	cout << "Copy constructor called\n";
	*this = fixed_var;
};

Fixed::~Fixed() {
	cout << "Destructor called\n";
};

Fixed &Fixed::operator = (const Fixed &fixed_var) {
	cout << "Copy assignment operator called\n";
	this->_value = fixed_var.getRawBits();
	return (*this);
};

int	Fixed::getRawBits(void) const {
	cout << "getRawBits member function called\n";
	return (this->_value);
};

void	Fixed::setRawBits(int const raw) {
	cout << "setRawBits member function called\n";
	this->_value = raw;
};