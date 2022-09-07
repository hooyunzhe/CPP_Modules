#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Colours.h"
# include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class	Bureaucrat;

class	Form {
	public:
		class	GradeTooHighException : public std::exception {
			public:
				GradeTooHighException(string type);
				~GradeTooHighException() throw ();
				const char	*what() const throw ();
				
			private:
				string	_type;
		};
		class	GradeTooLowException : public std::exception {
			public:
				GradeTooLowException(string type);
				~GradeTooLowException() throw();
				const char	*what() const throw ();
				
			private:
				string	_type;
		};
		Form(string name, int sign_grade, int execute_grade);
		Form(const Form &form_var);
		~Form();
		Form	&operator = (const Form &form_var);

		const string	getName(void) const;
		bool			isSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		void			beSigned(const Bureaucrat &bureaucrat_var);

	private:
		const string	_name;
		bool			_signed;
		const int		_sign_grade;
		const int		_execute_grade;
};

ostream	&operator << (ostream &out, const Form &form_var);

#endif