#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

enum	scalar {Char, Int, Float, Double, Invalid};

class	Converter {
	public:
		Converter(string literal);
		Converter(const Converter &converter_var);
		~Converter();
		Converter	&operator = (const Converter &converter_var);

		void	checkType();
		bool	checkOutOfRange(scalar);
		bool	checkPseudo();
		bool	checkDisplayable();
		void	printPseudo(scalar);
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();

	private:
		string	_literal;
		scalar	_type;
};

#endif
