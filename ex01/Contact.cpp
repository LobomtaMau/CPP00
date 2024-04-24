#include <PB_main.hpp>

Contact::Contact()
    : first_name(""), last_name(""), nick_name(""), phone_number(""), darkest_secret("") {}

void Contact::SetContactInfo() {
    std::cout << "Enter First Name: ";
    std::cin.ignore();
    std::getline(std::cin, first_name);
    std::replace(first_name.begin(), first_name.end(), '\t', ' ');
    while (first_name.empty()) {
        std::cout << "First Name empty. Please enter again: ";
        std::getline(std::cin, first_name);
        std::replace(first_name.begin(), first_name.end(), '\t', ' ');
    }

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, last_name);
    std::replace(last_name.begin(), last_name.end(), '\t', ' ');
    while (last_name.empty()) {
        std::cout << "Last Name empty. Please enter again: ";
        std::getline(std::cin, last_name);
        std::replace(last_name.begin(), last_name.end(), '\t', ' ');
    }

    std::cout << "Enter NickName: ";
    std::getline(std::cin, nick_name);
    std::replace(nick_name.begin(), nick_name.end(), '\t', ' ');
    while (nick_name.empty()) {
        std::cout << "NickName empty. Please enter again: ";
        std::getline(std::cin, nick_name);
        std::replace(nick_name.begin(), nick_name.end(), '\t', ' ');
    }

    std::cout << "Enter Phone number: ";
    std::getline(std::cin, phone_number);
    std::replace(phone_number.begin(), phone_number.end(), '\t', ' ');
    while (phone_number.empty()) {
        std::cout << "Phone number empty. Please enter again: ";
        std::getline(std::cin, phone_number);
        std::replace(phone_number.begin(), phone_number.end(), '\t', ' ');
    }

    std::cout << "Enter Your Darkest secrect: ";
    std::getline(std::cin, darkest_secret);
    std::replace(darkest_secret.begin(), darkest_secret.end(), '\t', ' ');
    while (darkest_secret.empty()) {
        std::cout << "Darkest secrect empty. Please enter again: ";
        std::getline(std::cin, darkest_secret);
        std::replace(darkest_secret.begin(), darkest_secret.end(), '\t', ' ');\
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