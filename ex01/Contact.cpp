#include <PB_main.hpp>

Contact::Contact()
    : first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {}

void Contact::SetContactInfo() {
    std::cout << "Enter First Name: ";
    getlineAndReplace(first_name);

    std::cout << "Enter Last Name: ";
    getlineAndReplace(last_name);

    std::cout << "Enter NickName: ";
    getlineAndReplace(nick_name);

    std::cout << "Enter Phone number: ";
    getlineAndReplace(phone_number);

    std::cout << "Enter Your Darkest secret: ";
    getlineAndReplace(darkest_secret);
}

void Contact::getlineAndReplace(std::string& str) {
    std::getline(std::cin, str);
    replaceTabsWithSpaces(str);
    while (str.empty()) {
        if(std::cin.eof())
            exit(EXIT_FAILURE);
        std::cout << str << "Empty. Please enter again: ";
        std::getline(std::cin, str);
        replaceTabsWithSpaces(str);
    }
}

void Contact::replaceTabsWithSpaces(std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (str[i] == '\t') {
            str[i] = ' ';
        }
    }
}

void Contact::DisplayContact(int i) {
    std::cout << std::right << std::setw(10) << i << "|";
    std::cout << std::right << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0,9) + "." : first_name) << "|";
    std::cout << std::right << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0,9) + "." : last_name) << "|";
    std::cout << std::right << std::setw(10) << (nick_name.length() > 10 ? nick_name.substr(0,9) + "." : nick_name) << std::endl;
}

std::string Contact::GetFirstName() const {
    return first_name;
}

std::string Contact::GetLastName() const {
    return last_name;
}

std::string Contact::GetNickName() const {
    return nick_name;
}

std::string Contact::GetPhoneNumber() const {
    return phone_number;
}

std::string Contact::GetDarkestSecret() const {
    return darkest_secret;
}