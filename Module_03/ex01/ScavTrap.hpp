#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(string name);
		ScavTrap(const ScavTrap &scavtrap_var);
		~ScavTrap();
		ScavTrap	&operator = (const ScavTrap &scavtrap_var);

		void	attack(const string &target);
		void	guardGate();
};

#endif