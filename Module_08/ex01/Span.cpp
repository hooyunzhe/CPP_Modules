#include "Span.hpp"

const char  *Span::SpanIsFull::what() const throw () {
	return (RED "Span is full...\n" RESET);
}

const char	*Span::SpanTooSmall::what() const throw () {
	return (RED "Span is too small...\n" RESET);
}

const char	*Span::IndexOutOfRange::what() const throw () {
	return (RED "Index is out of range...\n" RESET);
}

Span::Span(unsigned int n) {
	cout << GREEN "Span constructor called\n" RESET;
	this->_arr = new int[n];
	this->_size = n;
	this->_index = 0;
}

Span::Span(const Span &span_var) {
	cout << BLUE "Span copy constructor called\n" RESET;
	*this = span_var;
}

Span::~Span() {
	cout << RED "Span destructor called\n" RESET;
	delete[] this->_arr;
}

Span    &Span::operator = (const Span &span_var) {
	cout << CYAN "Span copy assignment operator called\n" RESET;
	if (span_var._size > 0) {
		delete[] span_var._arr;
	}
	this->_arr = new int[span_var._size];
	this->_size = span_var._size;
	std::copy(this->_arr, this->_arr + this->_size, span_var._arr);
	return (*this);
}

void    Span::addNumber(int number) {
	if (this->_index == this->_size) {
		throw SpanIsFull();
	}
	else {
		this->_arr[this->_index++] = number;
	}
}

int	getRandomNum(void) {
	return (rand() % 10000);
}

void	Span::fillSpan(void) {
	srand(time(NULL));
	std::generate(this->_arr, this->_arr + this->_size, getRandomNum);
	this->_index = this->_size;
}

int	getDiff(int x, int y) {
	return (abs(x - y));
}

int	Span::shortestSpan(void) const {
	int	*sorted_arr;
	int	*shifted_arr;
	int	*distances;
	int	shortest_span;

	if (this->_index < 2) {
		throw SpanTooSmall();
	}
	sorted_arr = new int[this->_index];
	shifted_arr = new int[this->_index];
	distances = new int[this->_index];
	std::copy(this->_arr, this->_arr + this->_index, sorted_arr);
	std::sort(sorted_arr, sorted_arr + this->_index);
	std::copy(sorted_arr, sorted_arr + this->_index, shifted_arr);
	std::rotate(shifted_arr, shifted_arr + 1, shifted_arr + this->_index);
	std::transform(sorted_arr, sorted_arr + this->_index, shifted_arr, distances, getDiff);
	shortest_span = *std::min_element(distances, distances + this->_index);
	delete[] sorted_arr;
	delete[] shifted_arr;
	delete[] distances;
	return (shortest_span);
}

int	Span::longestSpan(void) const {
	return (*std::max_element(this->_arr, this->_arr + this->_index) - *std::min_element(this->_arr, this->_arr + this->_index));
}

int	Span::size(void) const {
	return (this->_index);
}

int	Span::operator [] (int index) const {
	if (index >= this->_index) {
		throw IndexOutOfRange();
	}
	return (this->_arr[index]);
}

ostream	&operator << (ostream &out, const Span &span_var) {
	for (int i = 0; i < span_var.size(); i++) {
		out << YELLOW "[" << span_var[i] << "]" RESET;
	}
	out << endl;
	return (out);
}