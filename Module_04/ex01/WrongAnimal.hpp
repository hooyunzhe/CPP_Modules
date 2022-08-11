#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	WrongAnimal {
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &wronganimal_var);
		~WrongAnimal();
		WrongAnimal	&operator = (const WrongAnimal &wronganimal_var);

		string	getType(void) const;
		void	makeSound(void) const;

	protected:
		string	_type;
};

#endif
