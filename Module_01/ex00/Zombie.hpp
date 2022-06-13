#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

using std::cout;
using std::endl;
using std::string;

class	Zombie {
	public:
		Zombie();
		~Zombie();

		void	setName(string name);
		string	getName();
		void	annouce(void);

	private:
		string	name;
};

Zombie	*newZombie(string name);
void	randomChump(string name);

#endif