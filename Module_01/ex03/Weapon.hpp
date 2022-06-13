#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

using std::string;

class	Weapon {
	public:
		Weapon(string type);
		~Weapon();

		void			setType(string type);
		const string	&getType(void) const;

	private:
		string	_type;	
};

#endif