#include "Bureaucrat.hpp"

int	main(void) {
	// Instantiating a bureaucrat with a grade that is too high
	try {
		Bureaucrat b1("b1", -42);

		cout << b1;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		cout << e.what();
	}
	
	// Instantiating a bureaucrat with a grade that is too low
	try {
		Bureaucrat b2("b2", 4242);
		cout << b2;
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		cout << e.what();
	}

	// Incrementing the grade of a bureaucrat when it's at the maximum
	Bureaucrat b3("b3", 42);

	cout << b3;
	for (int i = 0; i < 42; i++) {
		try {
			b3.incrementGrade();
			cout << b3;
		}
		catch (Bureaucrat::GradeTooHighException & e) {
			cout << e.what();
		}
	}

	// Decrementing the grade of a bureaucrat when it's at the minimum
	Bureaucrat b4("b4", 142);

	cout << b4;
	for (int i = 0; i < 9; i++) {
		try {
			b4.decrementGrade();
			cout << b4;
		}
		catch (Bureaucrat::GradeTooLowException & e) {
			cout << e.what();
		}
	}

	// Instantiating a form with a sign grade that is too high
	try {
		Form f1("f1", -42, 42);
	}
	catch (Form::GradeTooHighException & e) {
		cout << e.what();
	}

	// Instantiating a form with a sign grade that is too low
	try {
		Form f1("f1", 4242, 42);
	}
	catch (Form::GradeTooLowException & e) {
		cout << e.what();
	}

	// Instantiating a form with a execute grade that is too high
	try {
		Form f1("f1", 42, -42);
	}
	catch (Form::GradeTooHighException & e) {
		cout << e.what();
	}

	// Instantiating a form with a execute grade that is too low
	try {
		Form f1("f1", 42, 4242);
	}
	catch (Form::GradeTooLowException & e) {
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