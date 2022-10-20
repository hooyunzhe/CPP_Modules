#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

template <typename T> class	Array {
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &array_var);
		~Array();
		Array	&operator = (const Array &array_var);

	private:
		T	_arr[];

};

#endif