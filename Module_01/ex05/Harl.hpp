#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

using std::cout;
using std::endl;
using std::string;

class	Harl {
	public:
		Harl();
		~Harl();

		void	complain(string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
		void	not_found(void);
};

#endif