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
		string	getName();
		void	annouce(void);
		Zombie	*newZombie(string name);
		void	randomChump(string name);

	private:
		string	name;
};

Zombie	*zombieHorde(int n, string name);

#endif