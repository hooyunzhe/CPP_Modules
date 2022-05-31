#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

using	std::cout;
using	std::endl;
using	std::string;

void	print_datetime(int datetime) {
	if (datetime < 10)
		cout << "0";
	cout << datetime;
}

void	print_field(string str, int field, int semicolon) {
	cout << str << field;
	if (semicolon)
		cout << ";";
}

void	print_init_status(int index, int amount) {
	print_field("index:", index, 1);
	print_field("amount:", amount, 1);
	cout << "created\n";
}

void	Account::_displayTimestamp() {
	time_t	now = time(0);
	tm 		*curr_time = localtime(&now);

	cout << "[" << 1900 + curr_time->tm_year;
	print_datetime(1 + curr_time->tm_mon);
	print_datetime(curr_time->tm_mday);
	cout << "_";
	print_datetime(curr_time->tm_hour);
	print_datetime(curr_time->tm_min);
	print_datetime(curr_time->tm_sec);
	cout << "] ";
}
void	Account::displayStatus() const {
	_displayTimestamp();
	print_field("index:", _accountIndex, 1);
	print_field("amount:", _amount, 1);
	print_field("deposits:", _nbDeposits, 1);
	print_field("withdrawals:", _nbWithdrawals, 0);
	cout << endl;
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	print_field("accounts:", _nbAccounts, 1);
	print_field("total:", _totalAmount, 1);
	print_field("deposits:", _totalNbDeposits, 1);
	print_field("withdrawals:", _totalNbWithdrawals, 0);
	cout << endl;
}

Account::Account() {
	_accountIndex = _nbAccounts;
	_amount = 0;
	_displayTimestamp();
	print_init_status(_accountIndex, _amount);
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_displayTimestamp();
	print_init_status(_accountIndex, _amount);
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account() {
	_displayTimestamp();
	print_field("index:", _accountIndex, 1);
	print_field("amount:", _amount, 1);
	cout << "closed\n";
}

int	Account::getNbAccounts() {
	return (_nbAccounts);
}

int	Account::getTotalAmount() {
	return (_totalAmount);
}

int	Account::getNbDeposits() {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (_totalNbWithdrawals);
}

int	Account::checkAmount() const {
	return (_amount);
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	print_field("index:", _accountIndex, 1);
	print_field("p_amount:", _amount, 1);
	print_field("deposit:", deposit, 1);
	_amount += deposit;
	_totalAmount += deposit;
	print_field("amount:", _amount, 1);
	_nbDeposits++;
	_totalNbDeposits++;
	print_field("nb_deposits:", _nbDeposits, 0);
	cout << endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	print_field("index:", _accountIndex, 1);
	print_field("p_amount:", _amount, 1);
	if (withdrawal < checkAmount()) {
		print_field("withdrawal:", withdrawal, 1);
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		print_field("amount:", _amount, 1);
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		print_field("nb_withdrawals:", _nbWithdrawals, 0);
		cout << endl;
		return (true);
	}
	cout << "withdrawal:refused\n";
	return (false);
}
