#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	Animal {
	public:
		Animal();
		Animal(const Animal &animal_var);
		virtual ~Animal();
		Animal	&operator = (const Animal &animal_var);

		string			getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		string	_type;
};

#endif
