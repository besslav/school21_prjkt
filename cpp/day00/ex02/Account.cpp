#include "Account.hpp"
#include <iostream>
#include <chrono>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

Account::Account() {
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
	Account::_totalAmount -= this->_amount;
	--Account::_nbAccounts;
}

static void print_value(int nb) {
	if (nb < 10)
		std::cout << "0";
	std::cout << nb;
}

void Account::_displayTimestamp() {
	time_t seconds = time(nullptr);
	tm* timeinfo = localtime(&seconds);
	std::cout << "[";
	std::cout << timeinfo->tm_year + 1900;
	print_value(timeinfo->tm_mon + 1);
	print_value(timeinfo->tm_mday);
	std::cout << "_";
	print_value(timeinfo->tm_hour);
	print_value(timeinfo->tm_min);
	print_value(timeinfo->tm_sec);
	std::cout << "] ";
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;

}

void Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposit:" << this->_nbDeposits<< ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;

}

void Account::makeDeposit(int deposit)
{
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	Account::_totalNbWithdrawals++;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}
