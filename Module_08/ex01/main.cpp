#include "Span.hpp"

// Testing Span
int main(void) {
    Span	s(5);

	s.addNumber(10);
	s.addNumber(20);
	s.addNumber(11);
	s.addNumber(12);
	s.addNumber(30);
	s.fillSpan();
	cout << s;
	cout << BLUE "Shortest span: " << GREEN << s.shortestSpan() << RESET << endl;
	cout << MAGENTA "Longest span: " << GREEN << s.longestSpan() << RESET << endl;
}