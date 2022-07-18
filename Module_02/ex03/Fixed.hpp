#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fixed;
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
		bool	operator > (const Fixed &to_comp);
		bool	operator < (const Fixed &to_comp);
		bool	operator >= (const Fixed &to_comp);
		bool	operator <= (const Fixed &to_comp);
		bool	operator == (const Fixed &to_comp);
		bool	operator != (const Fixed &to_comp);
		Fixed	operator + (const Fixed &to_add);
		Fixed	operator - (const Fixed &to_sub);
		Fixed	operator * (const Fixed &to_mul);
		Fixed	operator / (const Fixed &to_div);
		Fixed	&operator ++ (void);
		Fixed	&operator -- (void);
		Fixed	operator ++ (int);
		Fixed	operator -- (int);
		static Fixed		&min(Fixed &fixed_one, Fixed &fixed_two);
		static Fixed		&max(Fixed &fixed_one, Fixed &fixed_two);
		static const Fixed	&min(const Fixed &fixed_one, const Fixed &fixed_two);
		static const Fixed	&max(const Fixed &fixed_one, const Fixed &fixed_two);

	private:
		int					_value;
		static const int	_fract_bits = 8;
};

ostream	&operator << (ostream &out, const Fixed &fixed_var);

#endif