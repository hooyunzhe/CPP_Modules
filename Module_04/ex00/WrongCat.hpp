#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &wrongcat_var);
		~WrongCat();
		WrongCat	&operator = (const WrongCat &wrongcat_var);

		void	makeSound(void) const;
};

#endif
