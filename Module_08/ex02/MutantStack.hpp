#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

template <class T>
class	MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack &mutantstack_var);
		~MutantStack();
		MutantStack	&operator = (const MutantStack &mutantstack_var);

		typedef	typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef	typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin(void);
		const_iterator			begin(void) const;
		reverse_iterator		rbegin(void);
		const_reverse_iterator	rbegin(void) const;
		iterator				end(void);
		const_iterator			end(void) const;
		reverse_iterator		rend(void);
		const_reverse_iterator	rend(void) const;
};

#endif