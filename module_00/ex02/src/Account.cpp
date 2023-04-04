/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 06:38:08 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/12/30 06:38:09 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount << ";created\n";
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";
}

int	Account::getNbAccounts(void){return(_nbAccounts);}
int	Account::getTotalAmount(void){return(_totalAmount);}
int	Account::getNbDeposits(void){return(_totalNbDeposits);}
int	Account::getNbWithdrawals(void){return(_totalNbWithdrawals);}
int	Account::checkAmount(void)const{return (_amount);}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	_amount += deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";withdrawal:";
	if (withdrawal <= _amount)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		return (std::cout << std::endl, 1);
	}
	return (std::cout << "refused\n", 0);
}

void Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:"<< _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	t;
	char	str[19];

	std::time(&t);
	std::strftime(str, 19, "[%Y%m%d_%H%M%S] ", localtime(&t));
	std::cout << str;
}
