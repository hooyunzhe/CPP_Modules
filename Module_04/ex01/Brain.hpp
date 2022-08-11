#ifndef BRAIN_CPP
# define BRAIN_CPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class Brain {
	public:
		Brain();
		Brain(const Brain &brain_var);
		~Brain();
		Brain	&operator = (const Brain &brain_var);

		string	ideas[100];
};

#endif