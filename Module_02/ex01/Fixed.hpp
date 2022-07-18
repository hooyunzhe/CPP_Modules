#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::setprecision;

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed &fixed_var);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed	&operator = (const Fixed &fixed_var);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_value;
		static const int	_fract_bits = 8;
};

ostream	&operator << (ostream &out, const Fixed &fixed_var);

#endif