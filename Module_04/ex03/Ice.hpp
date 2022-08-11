#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &ice_var);
		~Ice();
		Ice	&operator = (const Ice &ice_var);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif