#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(string target);
		RobotomyRequestForm(const RobotomyRequestForm &scf_var);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator = (const RobotomyRequestForm &scf_var);

		void	execute(Bureaucrat const &executor) const;
};

#endif