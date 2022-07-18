#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed &fixed_var) {
	cout << "Copy constructor called\n";
	*this = fixed_var;
};

Fixed::Fixed(const int num) {
	cout << "Int constructor called\n";
	_value = roundf(num * (1 << this->_fract_bits));
};

Fixed::Fixed(const float num) {
	cout << "Float constructor called\n";
	_value = roundf(num * (1 << this->_fract_bits));
};

Fixed::~Fixed() {
	cout << "Destructor called\n";
};

Fixed	&Fixed::operator = (const Fixed &fixed_var) {
	cout << "Copy assignment operator called\n";
	this->_value = fixed_var._value;
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

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_fract_bits));
};

int		Fixed::toInt(void) const {
	return (this->_value / (1 << this->_fract_bits));
};

ostream	&operator << (ostream &out, const Fixed &fixed_var) {
	out << fixed_var.toFloat();
	return (out);
};
