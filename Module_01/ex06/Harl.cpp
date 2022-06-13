#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void	Harl::complain(string level) {
	int		i = 0;
	string	compFuncNames[5] = {
		"debug",
		"info",
		"warning",
		"error",
		"not found"
	};

	while (i < 4 && level.compare(compFuncNames[i])) {
		i++;
	}
	switch(i) {
		case 0:
			Harl::debug();
			Harl::info();
			Harl::warning();
			Harl::error();
			break;
		case 1:
			Harl::info();
			Harl::warning();
			Harl::error();
			break;
		case 2:
			Harl::warning();
			Harl::error();
			break;
		case 3:
			Harl::error();
			break;
		case 4:
			Harl::not_found();
			break;
	}
}

void	Harl::debug(void) {
	cout << "[ DEBUG ]\n";
	cout << "I love debugging my code after Eu Lee breaks it!!!\n";
}

void	Harl::info(void) {
	cout << "[ INFO ]\n";
	cout << "Eu Lee is exceptionally good at breaking code, he broke our Minishell multiple times!!!\n";
}

void	Harl::warning(void) {
	cout << "[ WARNING ]\n";
	cout << "You have to be careful around Eu Lee if you don't want your code broken!!!\n";
}

void	Harl::error(void) {
	cout << "[ ERROR ]\n";
	cout << "Oh NOOO Eu Lee has broken my code!!!\n";
}

void	Harl::not_found(void) {
	cout << "[ NOT FOUND ]\n";
	cout << "Eu Lee doesn't approve of your bullshit!!!\n";
}