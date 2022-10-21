#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <algorithm>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

class   Span {
	public:
		class	SpanIsFull : public std::exception {
			public:
				const char	*what() const throw ();
		};
		class	SpanTooSmall : public std::exception {
			public:
				const char	*what() const throw ();
		};
		class	IndexOutOfRange : public std::exception {
			public:
				const char	*what() const throw ();
		};
		Span(unsigned int n);
		Span(const Span &span_var);
		~Span();
		Span    &operator = (const Span &span_var);

		void    addNumber(int number);
		void	fillSpan(void);
		int     shortestSpan(void) const;
		int		longestSpan(void) const;
		int		size(void) const;
		int		operator [] (int index) const;

	private:
		int	*_arr;
		int	_size;
		int	_index;
};

ostream	&operator << (ostream &out, const Span &span_var);

#endif