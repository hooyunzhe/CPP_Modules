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

	if ((this->_literal[0] == '-' || this->_literal[0] == '+') && this->_literal[1] != 'n') {
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
	else if (std::count(to_check.begin(), to_check.end(), '.') == 1 && to_check.find_first_not_of(".0123456789f") == string::npos
		&& std::count(to_check.begin(), to_check.end(), 'f') == 1) {
		this->_type = Float;
	}
	else if (to_check == "inf" || to_check == "nan") {
		this->_type = Double;
	}
	else if (std::count(to_check.begin(), to_check.end(), '.') == 1 && to_check.find_first_not_of(".0123456789") == string::npos) {
		this->_type = Double;
	}
	else {
		this->_type = Invalid;
	}
	try {
		if (this->_type == Int) {
			std::stoi(this->_literal);
		}
		else if (this->_type == Float) {
			std::stof(this->_literal);
		}
		else if (this->_type == Double) {
			std::stod(this->_literal);
		}
	}
	catch (std::out_of_range &e) {
		this->_type = Invalid;
	}
}

bool	Converter::checkOutOfRange(scalar type) {
	try {
		if (type == Int) {
			std::stoi(this->_literal);
		}
		else if (type == Float) {
			std::stof(this->_literal);
		}
		return (false);
	}
	catch (std::out_of_range &e) {
		return (true);
	}
}

bool	Converter::checkPseudo() {
	return ((this->_type == Float && this->_literal.find_first_not_of("-+.0123456789f") != string::npos)
		|| (this->_type == Double && this->_literal.find_first_not_of("-+.0123456789") != string::npos));
}

bool	Converter::checkDisplayable() {
	if (this->_type == Char) {
		return (this->_literal[0] < 0 || this->_literal[0] >= ' ');
	}
	else if (this->_type == Int) {
		return (std::stoi(this->_literal) < 0 || std::stoi(this->_literal) >= 32);
	}
	else if (this->_type == Float) {
		return (std::stof(this->_literal) < 0.0f || std::stof(this->_literal) >= 32.0f);
	}
	else if (this->_type == Double) {
		return (std::stod(this->_literal) < 0.0 || std::stod(this->_literal) >= 32.0);
	}
	return (false);
}

void	Converter::printPseudo(scalar type) {
	if (this->_type == Float && type == Double) {
		cout << this->_literal.substr(0, this->_literal.size() - 1);
	}
	else if (this->_type == Double && type == Float) {
		cout << this->_literal << "f";
	}
	else {
		cout << this->_literal;
	}
}

void	Converter::printChar() {
	cout << "'";
	if (this->_type == Char) {
		cout << this->_literal;
	}
	else if (this->_type == Int) {
		cout << (char)(std::stoi(this->_literal));
	}
	else if (this->_type == Float) {
		cout << (char)(std::stof(this->_literal));
	}
	else if (this->_type == Double) {
		cout << (char)(std::stod(this->_literal));
	}
	cout << "'";
}

void	Converter::printInt() {
	if (this->_type == Char) {
		cout << (int)this->_literal[0];
	}
	else if (this->_type == Int) {
		cout << std::stoi(this->_literal);
	}
	else if (this->_type == Float) {
		cout << (int)std::stof(this->_literal);
	}
	else if (this->_type == Double) {
		cout << (int)std::stod(this->_literal);
	}
}

void	Converter::printFloat() {
	cout << std::fixed << std::setprecision(1);
	if (this->_type == Char) {
		cout << (float)this->_literal[0];
	}
	else if (this->_type == Int) {
		cout << (float)std::stoi(this->_literal);
	}
	else if (this->_type == Float) {
		cout << std::stof(this->_literal);
	}
	else if (this->_type == Double) {
		cout << (float)std::stod(this->_literal);
	}
	cout << "f";
}

void	Converter::printDouble() {
	cout << std::fixed << std::setprecision(1);
	if (this->_type == Char) {
		cout << (double)this->_literal[0];
	}
	else if (this->_type == Int) {
		cout << (double)std::stoi(this->_literal);
	}
	else if (this->_type == Float) {
		cout << (double)std::stof(this->_literal);
	}
	else if (this->_type == Double) {
		cout << std::stod(this->_literal);
	}
}

void	Converter::toChar() {
	cout << "char: ";
	if (this->_type == Invalid) {
		cout << "Invalid";
	}
	else if (this->checkPseudo()) {
		cout << "Impossible";
	}
	else if (this->checkDisplayable()) {
		this->printChar();
	}
	else {
		cout << "Non displayable";
	}
	cout << endl;
}

void	Converter::toInt() {
	cout << "int: ";
	if (this->_type == Invalid) {
		cout << "Invalid";
	}
	else if (this->checkOutOfRange(Int) || this->checkPseudo()) {
		cout << "Impossible";
	}
	else {
		this->printInt();
	}
	cout << endl;
}

void	Converter::toFloat() {
	cout << "float: ";
	if (this->_type == Invalid) {
		cout << "Invalid";
	}
	else if (this->checkOutOfRange(Float)) {
		cout << "Impossible";
	}
	else if (this->checkPseudo()) {
		this->printPseudo(Float);
	}
	else {
		this->printFloat();
	}
	cout << endl;
}

void	Converter::toDouble() {
	cout << "double: ";
	if (this->_type == Invalid) {
		cout << "Invalid";
	}
	else if (this->checkPseudo()) {
		this->printPseudo(Double);
	}
	else {
		this->printDouble();
	}
	cout << endl;
}
