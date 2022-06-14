#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	HumanA {
	public:
		HumanA(string name, Weapon &weapon);
		~HumanA();

		void	attack(void) const;

	private:
		string	_name;
		Weapon	&_weapon;
};

#endif