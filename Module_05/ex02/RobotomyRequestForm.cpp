#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string target) : AForm("RobotomyRequestForm", target, 72, 45) {
	cout << GREEN "RobotomyRequestForm constructor called\n" RESET;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf_var) : AForm(rrf_var.getName(), rrf_var.getTarget(), rrf_var.getSignGrade(), rrf_var.getExecuteGrade()) {
	cout << BLUE "RobotomyRequestForm copy constructor called\n" RESET;
	this->signForm(rrf_var.isSigned());
}

RobotomyRequestForm::~RobotomyRequestForm() {
	cout << RED "RobotomyRequestForm destrutor called\n" RESET;
}

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &rrf_var) {
	cout << CYAN "RobotomyRequestForm copy assignment operator called\n" RESET;
	this->signForm(rrf_var.isSigned());
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	this->checkExecutable(executor);
	cout << YELLOW "* INTENSE DRILLING NOISES *\n";
	srand(time(NULL));
	if (rand() % 2 == 0) {
		cout << GREEN << this->getTarget() << " has been robotomized successfully!\n";
	}
	else {
		cout << BLACK "Unfortunately, the robotomy on " << this->getTarget() << " has failed...\n";
	}
}