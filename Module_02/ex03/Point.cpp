#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	// cout << "Default constructor called\n";
};

Point::Point(const Point &point_var) : _x(point_var._x), _y(point_var._y) {
	// cout << "Copy constructor called\n";	
};

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
	// cout << "Float constructor called\n";
};

Point::~Point() {
	// cout << "Destructor called\n";
}

Point	&Point::operator = (const Point &point_var) {
	// cout << "Copy assignment operator called\n";
	Point	*new_point = new Point(point_var);
	return (*new_point);
};

const Fixed	&Point::getX(void) const {
	return (this->_x);
};

const Fixed	&Point::getY(void) const {
	return (this->_y);
};

ostream	&operator << (ostream &out, const Point &point_var) {
	out << "(" << point_var.getX() << ", " << point_var.getY() << ")";
	return (out);
};
