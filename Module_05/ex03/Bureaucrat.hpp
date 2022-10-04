#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <iostream>
# include <string>
# include "Colours.h"
# include "AForm.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class	AForm;

class	Bureaucrat {
	public:
		class	GradeTooHighException : public std::exception {
			public:
				const char	*what() const throw ();
		};
		class	GradeTooLowException : public std::exception {
			public:
				const char	*what() const throw ();
		};
		Bureaucrat(string name, int grade);
		Bureaucrat(const Bureaucrat &bureaucrat_var);
		~Bureaucrat();
		Bureaucrat	&operator = (const Bureaucrat &bureaucrat_var);

		const string	getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

		void			signForm(AForm &form_var) const;
		void			executeForm(AForm &form_var) const;

	private:
		const string	_name;
		int				_grade;
};

ostream	&operator << (ostream &out, const Bureaucrat &bureaucrat_var);

#endif