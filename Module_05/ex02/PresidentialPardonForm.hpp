#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(string target);
		PresidentialPardonForm(const PresidentialPardonForm &scf_var);
		~PresidentialPardonForm();
		PresidentialPardonForm	&operator = (const PresidentialPardonForm &scf_var);

		void	execute(Bureaucrat const &executor) const;
};

#endif