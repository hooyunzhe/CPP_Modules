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
	char	*end;

	if ((this->_literal[0] == '-' || this->_literal[0] == '+') && (isdigit(this->_literal[1]) || this->_literal[1] == 'i')) {
		to_check = this->_literal.substr(1, string::npos);
	}
	else {
		to_check = this->_literal;
	}
	if (this->_literal.length() == 1 && this->_literal[0] >= 32 && this->_literal[0] <= 126 && !isdigit(this->_literal[0])) {
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
	if (this->_type == Int && (std::strtod(this->_literal.c_str(), &end) < INT_MIN || std::strtod(this->_literal.c_str(), &end) > INT_MAX)) {
		this->_type = Double;
	}
}

bool	Converter::checkOutOfRange(scalar type) {
	char	*end;

	if ((type == Char && (std::strtod(this->_literal.c_str(), &end) < 0 || std::strtod(this->_literal.c_str(), &end) > 127)) ||
		(type == Int && (std::strtod(this->_literal.c_str(), &end) < INT_MIN || std::strtod(this->_literal.c_str(), &end) > INT_MAX))) {
		return (true);
	}
	return (false);
}

bool	Converter::checkPseudo() {
	return ((this->_type == Float && this->_literal.find_first_not_of("-+.0123456789f") != string::npos)
		|| (this->_type == Double && this->_literal.find_first_not_of("-+.0123456789") != string::npos));
}

bool	Converter::checkDisplayable() {
	char	*end;

	if (this->_type == Char) {
		return (this->_literal[0] >= ' ' && this->_literal[0] <= '~');
	}
	else if (this->_type == Int) {
		return (std::atoi(this->_literal.c_str()) >= 32 && std::atoi(this->_literal.c_str()) <= 126);
	}
	else if (this->_type == Float) {
		return (std::atof(this->_literal.c_str()) >= 32.0f && std::atof(this->_literal.c_str()) <= 126.0f);
	}
	else if (this->_type == Double) {
		return (std::strtod(this->_literal.c_str(), &end) >= 32.0 && std::strtod(this->_literal.c_str(), &end) <= 126.0);
	}
	return (false);
}

void	Converter::printPseudo(scalar type) {
	cout << GREEN;
	if (this->_type == Float && type == Double) {
		cout << this->_literal.substr((this->_literal[0] == '+'), this->_literal.length() - 1 - (this->_literal[0] == '+'));
	}
	else if (this->_type == Double && type == Float) {
		cout << this->_literal.substr((this->_literal[0] == '+'), this->_literal.length()) << "f";
	}
	else {
		cout << this->_literal.substr((this->_literal[0] == '+'), this->_literal.length());
	}
	cout << RESET;
}

void	Converter::printChar() {
	char	*end;

	cout << GREEN "'";
	if (this->_type == Char) {
		cout << this->_literal;
	}
	else if (this->_type == Int) {
		cout << static_cast<char>(std::atoi(this->_literal.c_str()));
	}
	else if (this->_type == Float) {
		cout << static_cast<char>(std::atof(this->_literal.c_str()));
	}
	else if (this->_type == Double) {
		cout << static_cast<char>(std::strtod(this->_literal.c_str(), &end));
	}
	cout << "'" RESET;
}

void	Converter::printInt() {
	char	*end;

	cout << GREEN;
	if (this->_type == Char) {
		cout << static_cast<int>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << std::atoi(this->_literal.c_str());
	}
	else if (this->_type == Float) {
		cout << static_cast<int>(std::strtod(this->_literal.c_str(), &end));
	}
	else if (this->_type == Double) {
		cout << static_cast<int>(std::strtod(this->_literal.c_str(), &end));
	}
	cout << RESET;
}

void	Converter::printFloat() {
	char	*end;

	cout << GREEN;
	if (this->_type == Char) {
		cout << static_cast<float>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << static_cast<float>(std::atoi(this->_literal.c_str()));
	}
	else if (this->_type == Float) {
		cout << std::atof(this->_literal.c_str());
	}
	else if (this->_type == Double) {
		cout << static_cast<float>(std::strtod(this->_literal.c_str(), &end));
	}
	if (this->_literal.length() <= 6 + (!isdigit(this->_literal[0])) && floor(std::atof(this->_literal.c_str())) == std::atof(this->_literal.c_str())) {
		cout << ".0";
	}
	cout << "f" RESET;
}

void	Converter::printDouble() {
	char	*end;

	cout << GREEN;
	if (this->_type == Char) {
		cout << static_cast<double>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << static_cast<double>(std::atoi(this->_literal.c_str()));
	}
	else if (this->_type == Float) {
		cout << static_cast<double>(std::strtod(this->_literal.c_str(), &end));
	}
	else if (this->_type == Double) {
		cout << std::strtod(this->_literal.c_str(), &end);
	}
	if (this->_literal.length() <= 6 + (!isdigit(this->_literal[0])) && floor(std::strtod(this->_literal.c_str(), &end)) == std::strtod(this->_literal.c_str(), &end)) {
		cout << ".0";
	}
	cout << RESET;
}

void	Converter::toChar() {
	cout << BLUE "char: " RESET;
	if (this->_type == Invalid) {
		cout << BLACK "Invalid" RESET;
	}
	else if (this->checkPseudo() || this->checkOutOfRange(Char)) {
		cout << RED "Impossible" RESET;
	}
	else if (this->checkDisplayable()) {
		this->printChar();
	}
	else {
		cout << YELLOW "Non displayable" RESET;
	}
	cout << endl;
}

void	Converter::toInt() {
	cout << BLUE "int: " RESET;
	if (this->_type == Invalid) {
		cout << BLACK "Invalid" RESET;
	}
	else if (this->checkPseudo() || this->checkOutOfRange(Int)) {
		cout << RED "Impossible" RESET;
	}
	else {
		this->printInt();
	}
	cout << endl;
}

void	Converter::toFloat() {
	cout << BLUE "float: " RESET;
	if (this->_type == Invalid) {
		cout << BLACK "Invalid" RESET;
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
	cout << BLUE "double: " RESET;
	if (this->_type == Invalid) {
		cout << BLACK "Invalid" RESET;
	}
	else if (this->checkPseudo()) {
		this->printPseudo(Double);
	}
	else {
		this->printDouble();
	}
	cout << endl;
}
