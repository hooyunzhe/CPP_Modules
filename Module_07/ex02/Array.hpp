#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

template <typename T> class	Array {
	public:
		class	IndexOutOfRange : public std::exception {
			public:
				const char	*what() const throw ();
		};
		Array();
		Array(unsigned int n);
		Array(const Array &array_var);
		~Array();
		Array	&operator = (const Array &array_var);

		T	&operator [] (int index) const;
		int	size(void) const;

	private:
		T	*_arr;
		int	_size;
};

template <class T>
ostream	&operator << (ostream &out, const Array<T> &array_var);

#endif