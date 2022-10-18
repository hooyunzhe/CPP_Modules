#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include "Colours.h"

using std::cout;
using std::endl;
using std::string;

class	Data {
	public:
		Data(string var);
		Data(const Data &data_var);
		~Data();
		Data	&operator = (const Data &data_var);

		string	getVar(void) const;
	
	private:
		string	_var;
};

#endif