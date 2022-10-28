#include "Span.hpp"

int main(void) {
	{
		Span	s(5);

		// If the Span has 1 or less numbers
		try {
			s.shortestSpan();
			s.longestSpan();
		}
		catch (Span::SpanTooSmall &e) {
			cout << e.what();
		}
		s.addNumber(10);
		s.addNumber(20);
		s.addNumber(11);
		s.addNumber(12);
		s.addNumber(30);

		// If index out of range
		try {
			cout << s[5] << endl;
		}
		catch (Span::IndexOutOfRange &e) {
			cout << e.what();
		}
		s.fillSpan();

		// If the Span is full
		try {
			s.addNumber(42);
		}
		catch (Span::SpanIsFull &e) {
			cout << e.what();
		}
		cout << YELLOW "s[0]: " << s[0] << RESET << endl;
		cout << s;
		cout << BLUE "Shortest span: " << GREEN << s.shortestSpan() << RESET << endl;
		cout << MAGENTA "Longest span: " << GREEN << s.longestSpan() << RESET << endl;
	}
	// Span with 10000 numbers
	{
		Span	s(10000);

		s.fillSpan();
		cout << s;
		cout << BLUE "Shortest span: " << GREEN << s.shortestSpan() << RESET << endl;
		cout << MAGENTA "Longest span: " << GREEN << s.longestSpan() << RESET << endl;
	}
}