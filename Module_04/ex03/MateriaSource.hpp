#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiasource_var);
		~MateriaSource();
		MateriaSource	&operator = (const MateriaSource &materiasource_var);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(string const &type);

	private:
		AMateria	*_templates[4];
};

#endif