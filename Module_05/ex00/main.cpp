#include "Bureaucrat.hpp"

int	main(void) {
	// Instantiating a bureaucrat with a grade that is too high
	try {
		Bureaucrat b1("b1", -42);

		cout << b1;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		cout << e.what();
	}
	
	// Instantiating a bureaucrat with a grade that is too low
	try {
		Bureaucrat b2("b2", 4242);
		cout << b2;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
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
		catch (Bureaucrat::GradeTooHighException &e) {
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
		catch (Bureaucrat::GradeTooLowException &e) {
			cout << e.what();
		}
	}
}