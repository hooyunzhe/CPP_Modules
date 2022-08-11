#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog_var);
		~Dog();
		Dog	&operator = (const Dog &dog_var);

		void	makeSound(void) const;
};

#endif
