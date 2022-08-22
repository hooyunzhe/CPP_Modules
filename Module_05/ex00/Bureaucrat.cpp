#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw () {
	return ("Grade too high, cannot be higher than 1...\n");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw () {
	return ("Grade too low, cannot be lower than 150...\n");
}

Bureaucrat::Bureaucrat(int grade) : _name("Bureaucrat") {
	cout << "Bureaucrat constructor called\n";
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat_var) {
	cout << "Bureaucrat copy constructor called\n";
	*this = bureaucrat_var;
}

Bureaucrat::~Bureaucrat() {
	cout << "Bureaucrat destructor called\n";
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &bureaucrat_var) {
	cout << "Bureaucrat copy assignment operator called\n";
	this->_grade = bureaucrat_var._grade;
	return (*this);
}

const string	Bureaucrat::getName(void) const {
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1) {
		throw GradeTooHighException();
	}
	else {
		this->_grade--;
	}
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150) {
		throw GradeTooLowException();
	}
	else {
		this->_grade++;
	}
}

ostream	&operator << (ostream &out, const Bureaucrat &bureaucrat_var) {
	out << bureaucrat_var.getName() << ", bureaucrat grade " << bureaucrat_var.getGrade() << ".\n";
	return (out);
}
