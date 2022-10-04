#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	// Testing Intern
	{
		Intern	junior;
		AForm	*form;

		form = junior.makeForm("  Shrubbery    Creation   Form    ", "most_beautiful");
		cout << *form;
		delete form;

		form = junior.makeForm("_ROBO_TOMY_RE_QUEST_FORM_", "Rival");
		cout << *form;
		delete form;

		form = junior.makeForm("-pReSiDeNtIaL--pArDoN--fOrM-", "Boss");
		cout << *form;
		delete form;

		form = junior.makeForm("SalaryIncreaseRequestForm", "Junior");
		cout << form << endl;
		delete form;

		form = junior.makeForm(" _si_-Ne C-Xi -E_b_# *(2-6(f $&F- T-_D&$ s*", "wiufehiu");
		cout << form << endl;
		delete form;
	}
	// Testing ShrubberyCreationForm created by Intern
	{
		Bureaucrat	gardener("Gardener", 50);
		Bureaucrat	boss("Boss", 140);
		Bureaucrat	child_of_boss("Child of Boss", 150);
		Intern		junior;
		AForm		*scf;

		// Successfully creating a form
		scf = junior.makeForm("ShrubberyCreationForm", "most_expensive");
		// Signing a form that requires a higher grade
		child_of_boss.signForm(*scf);
		// Executing a form before it's signed
		child_of_boss.executeForm(*scf);
		// Successfully signing a form
		boss.signForm(*scf);
		// Executing a form that requires a higher grade
		boss.executeForm(*scf);
		// Successfully executing a form
		gardener.executeForm(*scf);
	}
	// Testing RobotomyRequestForm created by Intern
	{
		Bureaucrat	doctor("Doctor", 25);
		Bureaucrat	patient("Patient", 50);
		Bureaucrat	assistant("Assistant", 75);
		Intern		junior;
		AForm		*rrf;

		// Successfully creating a form
		rrf = junior.makeForm("RobotomyRequestForm", "Biggest Bullshitter");
		// Signing it with a bureaucrat whose grade is too low
		assistant.signForm(*rrf);
		// Executing it before it's signed
		assistant.executeForm(*rrf);
		// Successfully signing it
		patient.signForm(*rrf);
		// Executing it with a bureaucrat whose grade is too low
		patient.executeForm(*rrf);
		// Successfully executing it
		doctor.executeForm(*rrf);
	}
	// Testing PresidentialPardonForm created by Intern
	{
		Bureaucrat	president("President", 1);
		Bureaucrat	vice_president("Vice President", 15);
		Bureaucrat	secretary("Secretary", 30);
		Intern		junior;
		AForm		*ppf;

		// Successfully creating a form
		ppf = junior.makeForm("PresidentialPardonForm", "Kindest Ever");
		// Signing it with a bureaucrat whose grade is too low
		secretary.signForm(*ppf);
		// Executing it before it's signed
		secretary.executeForm(*ppf);
		// Successfully signing it
		vice_president.signForm(*ppf);
		// Executing it with a bureaucrat whose grade is too low
		vice_president.executeForm(*ppf);
		// Successfully executing it
		president.executeForm(*ppf);
	}
}