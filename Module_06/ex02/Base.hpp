#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

class	Base {
	public:
		virtual	~Base();
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

#endif