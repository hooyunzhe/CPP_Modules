#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Colours.h"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;
using std::string;

class	Intern {
	public:
		Intern();
		Intern(const Intern &intern_var);
		~Intern();
		Intern	&operator = (const Intern &intern_var);

		AForm	*makeForm(string form, string target);
};

#endif