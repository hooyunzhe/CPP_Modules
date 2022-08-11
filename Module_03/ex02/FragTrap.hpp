#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {
	public:
		FragTrap(string name);
		FragTrap(const FragTrap &fragtrap_var);
		~FragTrap();
		FragTrap	&operator = (const FragTrap &fragtrap_var);

		void	highFivesGuys(void);
};

#endif