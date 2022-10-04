#include "Bureaucrat.hpp"

int	main(void) {
	// Instantiating a form with a sign grade that is too high
	try {
		Form f1("f1", -42, 42);
	}
	catch (Form::GradeTooHighException &e) {
		cout << e.what();
	}

	// Instantiating a form with a sign grade that is too low
	try {
		Form f1("f1", 4242, 42);
	}
	catch (Form::GradeTooLowException &e) {
		cout << e.what();
	}

	// Instantiating a form with a execute grade that is too high
	try {
		Form f1("f1", 42, -42);
	}
	catch (Form::GradeTooHighException &e) {
		cout << e.what();
	}

	// Instantiating a form with a execute grade that is too low
	try {
		Form f1("f1", 42, 4242);
	}
	catch (Form::GradeTooLowException &e) {
		cout << e.what();
	}

	// Signing a form successfully
	Form f1("f1", 42, 84);
	Bureaucrat b1("b1", 42);
	
	cout << f1;
	cout << b1;

	b1.signForm(f1);

	// Signing a form that requires a higher grade
	Form f2("f2", 21, 42);
	Bureaucrat b2("b2", 84);

	cout << f2;
	cout << b2;

	b2.signForm(f2);
}