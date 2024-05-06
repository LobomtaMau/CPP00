#include <Account.hpp>
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;



Account::Account( int initial_deposit )
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbWithdrawals(0) {
    _totalAmount += initial_deposit;
    _nbAccounts++;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account() {
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
    
}

void	Account::makeDeposit( int deposit ) {
    if (deposit > 0) {
        _amount += deposit;
        _nbDeposits++;
        _totalAmount += deposit;
        _totalNbDeposits++;
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount - deposit
                  << ";deposit:" << deposit
                  << ";amount:" << _amount
                  << ";nb_deposits:" << _nbDeposits << std::endl;
    }
}

bool Account::makeWithdrawal( int withdrawal ) {
    if(withdrawal > 0 && _amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;

        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount + withdrawal
                  << ";withdrawal:" << withdrawal
                  << ";amount:" << _amount
                  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true;
    } else {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
}


int Account::getNbAccounts(void) {
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const {
    return (Account::_amount);
}

void Account::_displayTimestamp( void ) {
    time_t atm;
    atm = time(NULL);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", std::localtime(&atm));
    std::cout << buffer;
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << checkAmount()
              << ";deposits:" << _nbDeposits
              << ";withdrawls:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawls:" << _totalNbWithdrawals << std::endl;

}
