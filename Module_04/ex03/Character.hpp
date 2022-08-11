#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class	Character : public ICharacter {
	public:
		Character(string name);
		Character(const Character &character_var);
		~Character();
		Character	&operator = (const Character &character_var);

		string const	&getName(void) const;
		void			equip(AMateria *m);
		void			unequip(int idx);
		void			use(int idx, ICharacter &target);

	private:
		string		_name;
		AMateria	*_inventory[4];
};

#endif