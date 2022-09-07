#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException(string type) {
	this->_type = type;
}

Form::GradeTooLowException::GradeTooLowException(string type) {
	this->_type = type;
}

Form::GradeTooHighException::~GradeTooHighException() throw() {}

Form::GradeTooLowException::~GradeTooLowException() throw() {}

const char	*Form::GradeTooHighException::what() const throw () {
	string	*err;

	err = new string(BLACK + this->_type + " grade too high, cannot be higher than 1...\n" RESET);
	return ((*err).c_str());
}

const char	*Form::GradeTooLowException::what() const throw () {
	string	*err;

	if (this->_type == "signing")
		err = new string(BLACK "it requires a higher grade than the Bureaucrat's\n" RESET);
	else
		err = new string(BLACK + this->_type + " grade too low, cannot be lower than 150...\n" RESET);
	return ((*err).c_str());
}

Form::Form(string name, int sign_grade, int execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	cout << GREEN "Form constructor called\n" RESET;
	if (this->_sign_grade < 1) {
		throw GradeTooHighException("sign");
	}
	else if (this->_sign_grade > 150) {
		throw GradeTooLowException("sign");
	}
	if (this->_execute_grade < 1) {
		throw GradeTooHighException("execute");
	}
	else if (this->_execute_grade > 150) {
		throw GradeTooLowException("execute");
	}
}

Form::Form(const Form &form_var) : _name(form_var._name), _sign_grade(form_var._sign_grade), _execute_grade(form_var._execute_grade) {
	cout << BLUE "Form copy constructor called\n" RESET;
	this->_signed = form_var._signed;
}

Form::~Form() {
	cout << RED "Form destructor called\n" RESET;
}

Form	&Form::operator = (const Form &form_var) {
	cout << CYAN "Form copy assignment operator called\n" RESET;
	this->_signed = form_var._signed;
	return (*this);
}

const string	Form::getName(void) const {
	return (this->_name);
}

bool	Form::isSigned(void) const {
	return (this->_signed);
}

int	Form::getSignGrade(void) const {
	return (this->_sign_grade);
}

int	Form::getExecuteGrade(void) const {
	return (this->_execute_grade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat_var) {
	if (bureaucrat_var.getGrade() > this->_sign_grade) {
		throw GradeTooLowException("signing");
	}
	this->_signed = true;
}

ostream	&operator << (ostream &out, const Form &form_var) {
	out << YELLOW << form_var.getName() << ", sign grade " << form_var.getSignGrade() << ", execute grade " << form_var.getExecuteGrade() << ", signed " << form_var.isSigned() << ".\n" RESET;
	return (out);
}
