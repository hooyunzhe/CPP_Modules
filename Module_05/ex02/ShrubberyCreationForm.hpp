#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &scf_var);
		~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator = (const ShrubberyCreationForm &scf_var);

		void	execute(Bureaucrat const &executor) const;
};

#endif