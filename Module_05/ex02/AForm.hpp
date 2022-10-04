#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <ctime>
# include "Colours.h"
# include "Bureaucrat.hpp"

using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::ofstream;

class	Bureaucrat;

class	AForm {
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
		class	FormNotSignedException : public std::exception {
			public:
				FormNotSignedException();
				~FormNotSignedException() throw();
				const char	*what() const throw();
		};
		AForm(string name, string target, int sign_grade, int execute_grade);
		AForm(const AForm &aform_var);
		virtual	~AForm();
		AForm	&operator = (const AForm &aform_var);

		const string	getName(void) const;
		string			getTarget(void) const;
		bool			isSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecuteGrade(void) const;

		void			signForm(bool status);

		void			beSigned(const Bureaucrat &bureaucrat_var);
		virtual void	execute(Bureaucrat const &executor) const;
		void			checkExecutable(const Bureaucrat &bureaucrat_var) const;

	private:
		const string	_name;
		string			_target;
		bool			_signed;
		const int		_sign_grade;
		const int		_execute_grade;
};

ostream	&operator << (ostream &out, const AForm &aform_var);

#endif