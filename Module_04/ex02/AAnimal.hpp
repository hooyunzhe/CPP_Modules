#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	AAnimal {
	public:
		AAnimal();
		AAnimal(const AAnimal &aanimal_var);
		virtual ~AAnimal();
		AAnimal	&operator = (const AAnimal &aanimal_var);

		string			getType(void) const;
		virtual void	makeSound(void) const = 0;
		
	protected:
		string	_type;
};

#endif
