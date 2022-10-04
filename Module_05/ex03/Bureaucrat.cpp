#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw () {
	return (BLACK "Grade too high, cannot be higher than 1...\n" RESET);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw () {
	return (BLACK "Grade too low, cannot be lower than 150...\n" RESET);
}

Bureaucrat::Bureaucrat(string name, int grade) : _name(name) {
	cout << GREEN "Bureaucrat constructor called\n" RESET;
	if (grade < 1) {
		throw GradeTooHighException();
	}
	else if (grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat_var) {
	cout << BLUE "Bureaucrat copy constructor called\n" RESET;
	*this = bureaucrat_var;
}

Bureaucrat::~Bureaucrat() {
	cout << RED "Bureaucrat destructor called\n" RESET;
}

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &bureaucrat_var) {
	cout << CYAN "Bureaucrat copy assignment operator called\n" RESET;
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

void	Bureaucrat::signForm(AForm &form_var) const {
	try {
		form_var.beSigned(*this);
		cout << GREEN << "Bureaucrat " << this->_name << " signed " << form_var.getName() << endl;
	}
	catch (AForm::GradeTooLowException &e) {
		cout << BLACK << "Bureaucrat " << this->_name << " couldn't sign " << form_var.getName() << " because " << e.what() << endl;
	}
}

void	Bureaucrat::executeForm(AForm &form_var) const {
	try {
		form_var.execute(*this);
		cout << GREEN << "Bureaucrat " << this->_name << " executed " << form_var.getName() << endl;
	}
	catch (AForm::FormNotSignedException &e) {
		cout << BLACK << "Bureaucrat " << this->_name << " couldn't execute " << form_var.getName() << " because " << e.what() << endl;
	}
	catch (AForm::GradeTooLowException &e) {
		cout << BLACK << "Bureaucrat " << this->_name << " couldn't execute " << form_var.getName() << " because " << e.what() << endl;
	}
}

ostream	&operator << (ostream &out, const Bureaucrat &bureaucrat_var) {
	out << YELLOW << bureaucrat_var.getName() << ", bureaucrat grade " << bureaucrat_var.getGrade() << ".\n" RESET;
	return (out);
}
