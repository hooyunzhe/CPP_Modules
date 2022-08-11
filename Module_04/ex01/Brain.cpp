#include "Brain.hpp"

Brain::Brain() {
	cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &brain_var) {
	cout << "Brain copy constructor called\n";
	*this = brain_var;
}

Brain::~Brain() {
	cout << "Brain destructor called\n";
}

Brain	&Brain::operator = (const Brain &brain_var) {
	cout << "Brain copy assignment operator called\n";
	std::copy(std::begin(brain_var.ideas), std::end(brain_var.ideas), std::begin(this->ideas));
 	return (*this);
}
