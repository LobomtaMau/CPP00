#include <PB_main.hpp>

int main() {
    PhoneBook phonebook;
    std::string cmd;

    // falta corrigir o ctrl D no getline
    //////////////////////////////////////////
    
    while (true) {
        std::cout << "Please enter a command (ADD, SEARCH, EXIT):";
        std::cin >> cmd;

        if(std::cin.eof())
            break;

        if(cmd == "ADD") {
            phonebook.AddContact();
        }
        else if( cmd == "SEARCH") {
            phonebook.SearchContact();
        }
        else if(cmd == "EXIT") {
            break;
        }
        else {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    }
    return 0;
}