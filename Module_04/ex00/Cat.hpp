#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat_var);
		~Cat();
		Cat	&operator = (const Cat &cat_var);

		void	makeSound(void) const;
};

#endif
