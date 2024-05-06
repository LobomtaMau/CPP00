#include <PB_main.hpp>

PhoneBook::PhoneBook()
    : old_i(0) {};

void PhoneBook::AddContact() {
    if (old_i >= MAX_CONCTACT)
        old_i = 0;

    contacts[old_i].SetContactInfo();
    old_i++;
}

void PhoneBook::SearchContact() {
    std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
    std::cout << "----------|----------|----------|----------" << std::endl;

    int index = 0;

    for(int i = 0; i < MAX_CONCTACT; i++) {
        if(!contacts[i].GetFirstName().empty()) {
            contacts[i].DisplayContact(i);
            index++;
        }
    }
    if (index == 0)
        return;

    std::cout << "Enter the index of the contact to display: ";
    
    while (!(std::cin >> index) || index < 0 || index > old_i) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid index. Please enter a valid index: ";
        if(std::cin.eof())
            break;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "First Name: " << contacts[index].GetFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].GetLastName() << std::endl;
    std::cout << "NickName: " << contacts[index].GetNickName() << std::endl;
    std::cout << "Phone Number: " << contacts[index].GetPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].GetDarkestSecret() << std::endl;
}
