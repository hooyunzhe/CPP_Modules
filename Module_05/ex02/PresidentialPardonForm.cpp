#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string target) : AForm("PresidentialPardonForm", target, 25, 5) {
	cout << GREEN "PresidentialPardonForm constructor called\n" RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf_var) : AForm(ppf_var.getName(), ppf_var.getTarget(), ppf_var.getSignGrade(), ppf_var.getExecuteGrade()) {
	cout << BLUE "PresidentialPardonForm copy constructor called\n" RESET;
	this->signForm(ppf_var.isSigned());
}

PresidentialPardonForm::~PresidentialPardonForm() {
	cout << RED "PresidentialPardonForm destrutor called\n" RESET;
}

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &ppf_var) {
	cout << CYAN "PresidentialPardonForm copy assignment operator called\n" RESET;
	this->signForm(ppf_var.isSigned());
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	this->checkExecutable(executor);
	cout << GREEN << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!\n";
}