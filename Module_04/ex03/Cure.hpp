#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria {
	public:
		Cure();
		Cure(const Cure &cure_var);
		~Cure();
		Cure	&operator = (const Cure &cure_var);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif