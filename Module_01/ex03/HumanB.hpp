#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	HumanB {
	public:
		HumanB(string name);
		~HumanB();

		void	attack(void) const;
		void	setWeapon(Weapon &weapon);

	private:
		string	_name;
		Weapon	*_weapon;
};

#endif