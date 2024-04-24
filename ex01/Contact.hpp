#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "PB_main.hpp"

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();

    void SetContactInfo();
    void DisplayContact(int i);

    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetNickName() const;
    std::string GetPhoneNumber() const;
    std::string GetDarkestSecret() const;
};

#endif
