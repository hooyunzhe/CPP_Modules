#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include "Colours.h"
# include "Data.hpp"

using std::cout;
using std::endl;
using std::string;

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif