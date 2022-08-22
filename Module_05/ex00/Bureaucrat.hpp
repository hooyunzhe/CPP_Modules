#ifndef BUREAUCRAT
# define BUREAUCRAT

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;
using std::ostream;

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
		Bureaucrat(int grade);
		Bureaucrat(const Bureaucrat &bureaucrat_var);
		~Bureaucrat();
		Bureaucrat	&operator = (const Bureaucrat &bureaucrat_var);

		const string	getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

	private:
		const string	_name;
		int				_grade;
};

ostream	&operator << (ostream &out, const Bureaucrat &bureaucrat_var);

#endif