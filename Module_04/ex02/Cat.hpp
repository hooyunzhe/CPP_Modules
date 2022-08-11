#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {
	public:
		Cat();
		Cat(const Cat &cat_var);
		~Cat();
		Cat	&operator = (const Cat &cat_var);

		void	makeSound(void) const;
	 	Brain	*getBrain(void) const;

	private:
		Brain	*_brain;
};

#endif
