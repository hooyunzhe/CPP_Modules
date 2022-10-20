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

	if ((this->_literal[0] == '-' || this->_literal[0] == '+') && isdigit(this->_literal[1])) {
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
		if ((this->_type == Float || this->_type == Double) && type == Int) {
			std::stoi(this->_literal);
		}
		else if (this->_type == Double && type == Float) {
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
		return (this->_literal[0] >= ' ' && this->_literal[0] <= '~');
	}
	else if (this->_type == Int) {
		return (std::stoi(this->_literal) >= 32 && std::stoi(this->_literal) <= 126);
	}
	else if (this->_type == Float) {
		return (std::stof(this->_literal) >= 32.0f && std::stof(this->_literal) <= 126.0f);
	}
	else if (this->_type == Double) {
		return (std::stod(this->_literal) >= 32.0 && std::stod(this->_literal) <= 126.0);
	}
	return (false);
}

void	Converter::printPseudo(scalar type) {
	cout << GREEN;
	if (this->_type == Float && type == Double) {
		cout << this->_literal.substr(0, this->_literal.size() - 1);
	}
	else if (this->_type == Double && type == Float) {
		cout << this->_literal << "f";
	}
	else {
		cout << this->_literal;
	}
	cout << RESET;
}

void	Converter::printChar() {
	cout << GREEN "'";
	if (this->_type == Char) {
		cout << this->_literal;
	}
	else if (this->_type == Int) {
		cout << static_cast<char>(std::stoi(this->_literal));
	}
	else if (this->_type == Float) {
		cout << static_cast<char>(std::stof(this->_literal));
	}
	else if (this->_type == Double) {
		cout << static_cast<char>(std::stod(this->_literal));
	}
	cout << "'" RESET;
}

void	Converter::printInt() {
	cout << GREEN;
	if (this->_type == Char) {
		cout << static_cast<int>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << std::stoi(this->_literal);
	}
	else if (this->_type == Float) {
		cout << static_cast<int>(std::stof(this->_literal));
	}
	else if (this->_type == Double) {
		cout << static_cast<int>(std::stod(this->_literal));
	}
	cout << RESET;
}

void	Converter::printFloat() {
	cout << GREEN;
	cout << std::fixed << std::setprecision(1);
	if (this->_type == Char) {
		cout << static_cast<float>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << static_cast<float>(std::stoi(this->_literal));
	}
	else if (this->_type == Float) {
		cout << std::stof(this->_literal);
	}
	else if (this->_type == Double) {
		cout << static_cast<float>(std::stod(this->_literal));
	}
	cout << "f" RESET;
}

void	Converter::printDouble() {
	cout << GREEN;
	cout << std::fixed << std::setprecision(1);
	if (this->_type == Char) {
		cout << static_cast<double>(this->_literal[0]);
	}
	else if (this->_type == Int) {
		cout << static_cast<double>(std::stoi(this->_literal));
	}
	else if (this->_type == Float) {
		cout << static_cast<double>(std::stof(this->_literal));
	}
	else if (this->_type == Double) {
		cout << std::stod(this->_literal);
	}
	cout << RESET;
}

void	Converter::toChar() {
	cout << BLUE "char: " RESET;
	if (this->_type == Invalid) {
		cout << BLACK "Invalid" RESET;
	}
	else if (this->checkPseudo()) {
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
	else if (this->checkOutOfRange(Float)) {
		cout << RED "Impossible" RESET;
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
