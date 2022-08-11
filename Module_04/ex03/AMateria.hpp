#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

using std::cout;
using std::endl;
using std::string;

class	AMateria {
	public:
		AMateria(string const &type);
		AMateria(const AMateria &amateria_var);
		virtual ~AMateria();
		AMateria	&operator = (const AMateria &amateria_var);

		string const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		string	_type;
};

#endif