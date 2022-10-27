#include "MutantStack.tpp"

int	main(void) {
	MutantStack<int>	mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);

	cout << GREEN << mstack.top() << endl;
	cout << BLUE "MutantStack size: " << mstack.size() << endl;

	// Forward iterator
	MutantStack<int>::iterator	begin = mstack.begin();
	MutantStack<int>::iterator	end = mstack.end();

	++begin;
	--begin;
	*begin = 42;
	while (begin != end)
	{
		cout << YELLOW << *begin << RESET << endl;
		++begin;
	}
	cout << endl;

	// Const forward iterator
	MutantStack<int>::const_iterator	cbegin = mstack.begin();
	MutantStack<int>::const_iterator	cend = mstack.end();

	++cbegin;
	--cbegin;
	// Can't modify since it's const
	// *cbegin = 42;
	while (cbegin != cend)
	{
		cout << YELLOW << *cbegin << RESET << endl;
		++cbegin;
	}
	cout << endl;

	// Backward iterator
	MutantStack<int>::reverse_iterator	rbegin = mstack.rbegin();
	MutantStack<int>::reverse_iterator	rend = mstack.rend();

	++rbegin;
	--rbegin;
	*rbegin = 42;
	while (rbegin != rend)
	{
		cout << YELLOW << *rbegin << RESET << endl;
		++rbegin;
	}
	cout << endl;

	// Const backward iterator
	MutantStack<int>::const_reverse_iterator	crbegin = mstack.rbegin();
	MutantStack<int>::const_reverse_iterator	crend = mstack.rend();

	++crbegin;
	--crbegin;
	// Can't modify since it's const
	// *crbegin = 42;
	while (crbegin != crend)
	{
		cout << YELLOW << *crbegin << RESET << endl;
		++crbegin;
	}
	cout << endl;
}