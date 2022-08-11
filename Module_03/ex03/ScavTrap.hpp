#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(string name);
		ScavTrap(const ScavTrap &scavtrap_var);
		~ScavTrap();
		ScavTrap	&operator = (const ScavTrap &scavtrap_var);

		void	attack(const string &target);
		void	guardGate(void);
	
	protected:
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
};

#endif