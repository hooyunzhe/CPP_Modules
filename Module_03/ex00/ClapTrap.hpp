#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	ClapTrap {
	public:
		ClapTrap(string name);
		ClapTrap(const ClapTrap &claptrap_var);
		~ClapTrap();
		ClapTrap	&operator = (const ClapTrap &claptrap_var);

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		string	_name;
		int		_hit_points;
		int		_energy_points;
		int		_attack_damage;
};

#endif