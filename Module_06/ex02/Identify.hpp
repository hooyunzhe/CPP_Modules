#ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

# include <iostream>
# include <string>
# include "Colours.h"
# include "Base.hpp"

using std::cout;
using std::endl;
using std::string;

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif