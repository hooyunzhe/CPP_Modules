#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class	Point {
	public:
		Point();
		Point(const Point &point_var);
		Point(const float x, const float y);
		~Point();
		Point	&operator = (const Point &point_var);

		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

ostream	&operator << (ostream &out, const Point &point_var);

#endif