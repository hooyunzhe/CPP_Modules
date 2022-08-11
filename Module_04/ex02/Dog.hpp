#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal {
	public:
		Dog();
		Dog(const Dog &dog_var);
		~Dog();
		Dog	&operator = (const Dog &dog_var);

		void	makeSound(void) const;
		Brain	*getBrain(void) const;
 
	private:
		Brain	*_brain;
};

#endif
