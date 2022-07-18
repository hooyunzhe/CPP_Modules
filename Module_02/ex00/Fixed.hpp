#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed	&operator = (const Fixed &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_value;
		static const int	_fract_bits = 8;
};

#endif