#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	// Testing ShrubberyCreationForm
	{
		Bureaucrat	gardener("Gardener", 50);
		Bureaucrat	boss("Boss", 140);
		Bureaucrat	child_of_boss("Child of Boss", 150);
		ShrubberyCreationForm scf("most_expensive");

		// Signing a form that requires a higher grade
		child_of_boss.signForm(scf);
		// Executing a form before it's signed
		child_of_boss.executeForm(scf);
		// Successfully signing a form
		boss.signForm(scf);
		// Executing a form that requires a higher grade
		boss.executeForm(scf);
		// Successfully executing a form
		gardener.executeForm(scf);
	}
	// Testing RobotomyRequestForm
	{
		Bureaucrat	doctor("Doctor", 25);
		Bureaucrat	patient("Patient", 50);
		Bureaucrat	assistant("Assistant", 75);
		RobotomyRequestForm	rrf("Biggest Bullshitter");

		// Signing it with a bureaucrat whose grade is too low
		assistant.signForm(rrf);
		// Executing it before it's signed
		assistant.executeForm(rrf);
		// Successfully signing it
		patient.signForm(rrf);
		// Executing it with a bureaucrat whose grade is too low
		patient.executeForm(rrf);
		// Successfully executing it
		doctor.executeForm(rrf);
	}
	// Testing PresidentialPardonForm
	{
		Bureaucrat	president("President", 1);
		Bureaucrat	vice_president("Vice President", 15);
		Bureaucrat	secretary("Secretary", 30);
		PresidentialPardonForm	ppf("Kindest Ever");

		// Signing it with a bureaucrat whose grade is too low
		secretary.signForm(ppf);
		// Executing it before it's signed
		secretary.executeForm(ppf);
		// Successfully signing it
		vice_president.signForm(ppf);
		// Executing it with a bureaucrat whose grade is too low
		vice_president.executeForm(ppf);
		// Successfully executing it
		president.executeForm(ppf);
	}
}