#ifndef SEDPLUS_HPP
# define SEDPLUS_HPP

# include <iostream>
# include <fstream>
# include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;

class	SedPlus {
	public:
		SedPlus();
		~SedPlus();

		int		checkInput(int argc, char **argv) const;
		void	writePlus(ofstream &output_file, string oriString, string oldString, string newString) const;
		void	sedPlus(string filename, string oldString, string newString) const;
};

#endif