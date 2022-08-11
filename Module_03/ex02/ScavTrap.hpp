#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap {
	public:
		ScavTrap(string name);
		ScavTrap(const ScavTrap &scavtrap_var);
		~ScavTrap();
		ScavTrap	&operator = (const ScavTrap &scavtrap_var);

		void	attack(const string &target);
		void	guardGate(void);
};

#endif