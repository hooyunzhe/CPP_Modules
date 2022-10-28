#include "Identify.hpp"

Base	*generate(void) {
	int	type;

	srand(time(NULL));
	type = rand() % 3;
	if (type == 0) {
		return (new A());
	}
	else if (type == 1) {
		return (new B());
	}
	else {
		return (new C());
	}
}

void	identify(Base *p) {
	cout << YELLOW "The argument points to an instance of Base class " RESET;
	if (dynamic_cast<A*>(p)) {
		cout << GREEN "A\n" RESET;
	}
	else if (dynamic_cast<B*>(p)) {
		cout << GREEN "B\n" RESET;
	}
	else if (dynamic_cast<C*>(p)) {
		cout << GREEN "C\n" RESET;
	}
}

void	identify(Base &p) {
	cout << YELLOW "The argument references an instance of Base class " RESET;
	try {
		(void)dynamic_cast<A&>(p);
		cout << GREEN "A\n" RESET;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		cout << GREEN "B\n" RESET;
	}
	catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		cout << GREEN "C\n" RESET;
	}
	catch (std::bad_cast &e) {}
}