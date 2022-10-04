#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(string type) {
	this->_type = type;
}

AForm::GradeTooLowException::GradeTooLowException(string type) {
	this->_type = type;
}

AForm::FormNotSignedException::FormNotSignedException() {
	
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::FormNotSignedException::~FormNotSignedException() throw() {}

const char	*AForm::GradeTooHighException::what() const throw () {
	string	*err;

	err = new string(BLACK + this->_type + " grade too high, cannot be higher than 1..." RESET);
	return ((*err).c_str());
}

const char	*AForm::GradeTooLowException::what() const throw () {
	string	*err;

	if (this->_type == "signing" || this->_type == "executing")
		err = new string(BLACK "it requires a higher grade than the Bureaucrat's" RESET);
	else
		err = new string(BLACK + this->_type + " grade too low, cannot be lower than 150..." RESET);
	return ((*err).c_str());
}

const char	*AForm::FormNotSignedException::what() const throw () {
	string	*err;

	err = new string(BLACK "it hasn't been signed" RESET);
	return ((*err).c_str());
}

AForm::AForm(string name, string target, int sign_grade, int execute_grade) : _name(name), _target(target), _sign_grade(sign_grade), _execute_grade(execute_grade) {
	cout << GREEN "AForm constructor called\n" RESET;
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

AForm::AForm(const AForm &aform_var) : _name(aform_var._name), _sign_grade(aform_var._sign_grade), _execute_grade(aform_var._execute_grade) {
	cout << BLUE "AForm copy constructor called\n" RESET;
	this->_signed = aform_var._signed;
}

AForm::~AForm() {
	cout << RED "AForm destructor called\n" RESET;
}

AForm	&AForm::operator = (const AForm &aform_var) {
	cout << CYAN "AForm copy assignment operator called\n" RESET;
	this->_signed = aform_var._signed;
	return (*this);
}

const string	AForm::getName(void) const {
	return (this->_name);
}

string	AForm::getTarget(void) const {
	return (this->_target);
}

bool	AForm::isSigned(void) const {
	return (this->_signed);
}

int	AForm::getSignGrade(void) const {
	return (this->_sign_grade);
}

int	AForm::getExecuteGrade(void) const {
	return (this->_execute_grade);
}

void	AForm::signForm(bool status) {
	this->_signed = status;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat_var) {
	if (bureaucrat_var.getGrade() > this->_sign_grade) {
		throw GradeTooLowException("signing");
	}
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	cout << "AForm executed by " << executor.getName() << endl;
}

void	AForm::checkExecutable(const Bureaucrat &bureaucrat_var) const {
	if (!this->_signed) {
		throw FormNotSignedException();
	}
	if (this->_execute_grade < bureaucrat_var.getGrade()) {
		throw GradeTooLowException("executing");
	}
}

ostream	&operator << (ostream &out, const AForm &aform_var) {
	out << YELLOW << aform_var.getName() << ", sign grade " << aform_var.getSignGrade() << ", execute grade " << aform_var.getExecuteGrade() << ", signed " << aform_var.isSigned() << ".\n" RESET;
	return (out);
}
