#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap {
	public:
		FragTrap(string name);
		FragTrap(const FragTrap &fragtrap_var);
		~FragTrap();
		FragTrap	&operator = (const FragTrap &fragtrap_var);

		void	highFivesGuys(void);
	
	protected:
		int	_hit_points;
		int	_energy_points;
		int	_attack_damage;
};

#endif