#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(string name);
		DiamondTrap(const DiamondTrap &diamondtrap_var);
		~DiamondTrap();
		DiamondTrap	&operator = (const DiamondTrap &diamondtrap_var);

		void	attack(const string &target);
		void	whoAmI(void) const;

	private:
		string	_name;
};

#endif