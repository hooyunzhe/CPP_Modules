#include "Intern.hpp"

Intern::Intern() {
	cout << GREEN "Intern constructor called\n" RESET;
};

Intern::Intern(const Intern &intern_var) {
	cout << BLUE "Intern copy constructor called\n" RESET;
	(void)intern_var;
}

Intern::~Intern() {
	cout << RED "Intern destructor called\n" RESET;
}

Intern	&Intern::operator = (const Intern &intern_var) {
	cout << CYAN "Intern copy assignment operator called\n" RESET;
	(void)intern_var;
	return (*this);
}

AForm	*Intern::makeForm(string form, string target) {
	string	form_names[] = {"shrubberycreation", "robotomyrequest", "presidentialpardon"};
	ShrubberyCreationForm	*scf = new ShrubberyCreationForm(target);
	RobotomyRequestForm		*rrf = new RobotomyRequestForm(target);
	PresidentialPardonForm	*ppf = new PresidentialPardonForm(target);
	AForm	*forms[] = {scf, rrf, ppf};
	string	form_to_check;

	form_to_check = form;
	form_to_check.erase(std::remove(form_to_check.begin(), form_to_check.end(), ' '), form_to_check.end());
	form_to_check.erase(std::remove(form_to_check.begin(), form_to_check.end(), '-'), form_to_check.end());
	form_to_check.erase(std::remove(form_to_check.begin(), form_to_check.end(), '_'), form_to_check.end());

	std::transform(form_to_check.begin(), form_to_check.end(), form_to_check.begin(), ::tolower);

	for (int i = 0; i < 3; i++) {
		if (form_to_check == form_names[i] || form_to_check == form_names[i] + "form") {
			for (int j = 0; j < 3; j++) {
				if (j != i) {
					delete forms[j];
				}
			}
			cout << GREEN "Intern created " << forms[i]->getName() << " successfully!\n" RESET;
			return (forms[i]);
		}
	}
	cout << RED "Intern couldn't create " << form << " because it doesn't exist...\n" RESET;
	return (NULL);
}