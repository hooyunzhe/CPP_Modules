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
	void (Harl::*compFuncs[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::not_found
	};

	while (i < 4 && level.compare(compFuncNames[i])) {
		i++;
	}
	(this->*compFuncs[i])();
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