#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	Zombie {
	public:
		Zombie();
		~Zombie();

		void	setName(string name);
		string	getName() const;
		void	annouce(void) const;

	private:
		string	_name;
};

Zombie	*newZombie(string name);
void	randomChump(string name);

#endif