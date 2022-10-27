#ifndef	MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack() : std::stack<T>() {
	cout << GREEN "MutantStack default constructor called\n" RESET;
}

template <class T>
MutantStack<T>::MutantStack(const MutantStack &mutantstack_var) : std::stack<T>(mutantstack_var) {
	cout << BLUE "MutantStack copy constructor called\n" RESET;
}

template <class T>
MutantStack<T>::~MutantStack() {
	cout << RED "MutantStack destructor called\n" RESET;
}

template <class T>
MutantStack<T>	&MutantStack<T>::operator = (const MutantStack &mutantstack_var) {
	cout << CYAN "MutantStack copy assignment operator called\n" RESET;
	std::stack<T>::operator=(mutantstack_var);
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void) {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const {
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin(void) {
	return (this->c.rbegin());
}

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rbegin(void) const {
	return (this->c.rbegin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void) {
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const {
	return (this->c.end());
}

template <class T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend(void) {
	return (this->c.rend());
}

template <class T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::rend(void) const {
	return (this->c.rend());
}

#endif