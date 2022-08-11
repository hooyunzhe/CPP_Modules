#ifndef ICHARACTERSOURCE_HPP
# define ICHARACTERSOURCE_HPP

# include "AMateria.hpp"

class	IMateriaSource {
	public:
		virtual	~IMateriaSource() {};
		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(string const &type) = 0;
};

#endif