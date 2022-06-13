#include <iostream>

using std::cout;
using std::endl;
using std::string;

int	main(void)
{
	string	brain = "HI THIS IS BRAIN";
	string	*stringPTR = &brain;
	string	&stringREF = brain;

	cout << &brain << endl;
	cout << stringPTR << endl;
	cout << &stringREF << endl;

	cout << brain << endl;
	cout << *stringPTR << endl;
	cout << stringREF << endl;
}