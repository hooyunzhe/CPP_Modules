#include "Converter.hpp"

Converter::Converter(string literal) : _literal(literal) {
	cout << GREEN "Converter constructor called\n" RESET;
}

Converter::Converter(const Converter &converter_var) {
	cout << BLUE "Converter copy constructor called\n" RESET;
	*this = converter_var;
}

Converter::~Converter() {
	cout << RED "Converter destructor called\n" RESET;
}

Converter	&Converter::operator = (const Converter &converter_var) {
	cout << CYAN "Converter copy assignment operator called\n" RESET;
	this->_literal = converter_var._literal;
	this->_type = converter_var._type;
	return (*this);
}

void	Converter::checkType() {
	string	to_check;

	if (this->_literal[0] == '-' || this->_literal[0] == '+') {
		to_check = this->_literal.substr(1, string::npos);
	}
	else {
		to_check = this->_literal;
	}
	if (to_check.length() == 1 && isalpha(to_check[0])) {
		this->_type = Char;
	}
	else if (to_check.find_first_not_of("0123456789") == string::npos) {
		this->_type = Int;
	}
	else if (to_check == "inff" || to_check == "nanf") {
		this->_type = Float;
	}
	else if (std::count(to_check.begin(), to_check.end(), '.') == 1 && to_check.find_first_not_of(".0123456789") == string::npos) {
		this->_type = Float;
	}
	else if (to_check == "inf" || to_check == "nan") {
		this->_type = Double;
	}
	else if (std::count(to_check.begin(), to_check.end(), 'f') == 1 && to_check.find_first_not_of(".0123456789f") == string::npos) {
		this->_type = Double;
	}
	else {
		this->_type = Invalid;
	}
}

void	Converter::toChar() {
	cout << "char: ";
	if (this->_type == Char) {
		cout << "Type: Char\n";
	}
	else if (this->_type == Int) {
		cout << "Type: Int\n";
	}
	else if (this->_type == Float) {
		cout << "Type: Float\n";
	}
	else if (this->_type == Double) {
		cout << "Type: Double\n";
	}
	else if (this->_type == Invalid) {
		cout << "Type: Invalid\n";
	}
}
