#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "PB_main.hpp"

class PhoneBook
{
private:
    static const int MAX_CONCTACT = 2;
    Contact contacts[MAX_CONCTACT];
    int old_i;
    
public:
    PhoneBook();

    void AddContact();
    void SearchContact();
};

#endif


// The cherno