#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	// cout << "Default constructor called\n";
};

Fixed::Fixed(const Fixed &fixed_var) : _value(fixed_var.getRawBits()) {
	// cout << "Copy constructor called\n";
};

Fixed::Fixed(const int num) {
	// cout << "Int constructor called\n";
	_value = roundf(num * (1 << this->_fract_bits));
};

Fixed::Fixed(const float num) {
	// cout << "Float constructor called\n";
	_value = roundf(num * (1 << this->_fract_bits));
};

Fixed::~Fixed() {
	// cout << "Destructor called\n";
};

Fixed	&Fixed::operator = (const Fixed &fixed_var) {
	// cout << "Copy assignment operator called\n";
	this->_value = fixed_var.getRawBits();
	return (*this);
};

int	Fixed::getRawBits(void) const {
	// cout << "getRawBits member function called\n";
	return (this->_value);
};

void	Fixed::setRawBits(int const raw) {
	// cout << "setRawBits member function called\n";
	this->_value = raw;
};

float	Fixed::toFloat(void) const {
	return ((float)this->_value / (float)(1 << this->_fract_bits));
};

int		Fixed::toInt(void) const {
	return (this->_value / (1 << this->_fract_bits));	
};

bool	Fixed::operator > (const Fixed &to_comp) {
	return (this->toFloat() > to_comp.toFloat());
};

bool	Fixed::operator < (const Fixed &to_comp) {
	return (this->toFloat() < to_comp.toFloat());
};

bool	Fixed::operator >= (const Fixed &to_comp) {
	return (this->toFloat() >= to_comp.toFloat());
};

bool	Fixed::operator <= (const Fixed &to_comp) {
	return (this->toFloat() <= to_comp.toFloat());
};

bool	Fixed::operator == (const Fixed &to_comp) {
	return (this->toFloat() == to_comp.toFloat());	
};

bool	Fixed::operator != (const Fixed &to_comp) {
	return (this->toFloat() != to_comp.toFloat());
};

Fixed	Fixed::operator + (const Fixed &to_add) {
	return (Fixed(this->toFloat() + to_add.toFloat()));
};

Fixed	Fixed::operator - (const Fixed &to_sub) {
	return (Fixed(this->toFloat() - to_sub.toFloat()));
};

Fixed	Fixed::operator * (const Fixed &to_mul) {
	return (Fixed(this->toFloat() * to_mul.toFloat()));
};

Fixed	Fixed::operator / (const Fixed &to_div) {
	return (Fixed(this->toFloat() / to_div.toFloat()));
};

Fixed	&Fixed::operator ++ (void) {
	this->_value++;
	return (*this);
};

Fixed	&Fixed::operator -- (void) {
	this->_value--;
	return (*this);
};

Fixed	Fixed::operator ++ (int) {
	Fixed	temp(*this);

	this->_value++;
	return (temp);
};

Fixed	Fixed::operator -- (int) {
	Fixed	temp(*this);

	this->_value--;
	return (temp);
};

Fixed	&Fixed::min(Fixed &fixed_one, Fixed &fixed_two) {
	if (fixed_one.toFloat() < fixed_two.toFloat()) {
		return (fixed_one);
	}
	else {
		return (fixed_two);
	}
};

Fixed	&Fixed::max(Fixed &fixed_one, Fixed &fixed_two) {
	if (fixed_one.toFloat() > fixed_two.toFloat()) {
		return (fixed_one);
	}
	else {
		return (fixed_two);
	}
};

const Fixed	&Fixed::min(const Fixed &fixed_one, const Fixed &fixed_two) {
	if (fixed_one.toFloat() < fixed_two.toFloat()) {
		return (fixed_one);
	}
	else {
		return (fixed_two);
	}
};

const Fixed	&Fixed::max(const Fixed &fixed_one, const Fixed &fixed_two) {
	if (fixed_one.toFloat() > fixed_two.toFloat()) {
		return (fixed_one);
	}
	else {
		return (fixed_two);
	}
}

ostream	&operator << (ostream &out, const Fixed &fixed_var) {
	out << fixed_var.toFloat();
	return (out);
};
