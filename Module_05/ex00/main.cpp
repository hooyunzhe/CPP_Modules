#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat b1(42);
		Bureaucrat b2(4242);

		cout << b1;
		cout << b2;
	}
	catch (Bureaucrat::GradeTooHighException & e) {
		cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException & e) {
		cout << e.what();
	}
}