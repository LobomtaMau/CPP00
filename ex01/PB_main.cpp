#include <PB_main.hpp>

void validLine(std::string &input) {
    std::getline(std::cin, input);
    if(std::cin.eof()){
        std::cout << "EOF.....\n";
        exit(EXIT_FAILURE);
    }
}

int main() {
    PhoneBook phonebook;
    std::string cmd;
    
    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        validLine(cmd);

        if(cmd == "ADD")
            phonebook.AddContact();
        else if( cmd == "SEARCH")
            phonebook.SearchContact();
        else if(cmd == "EXIT")
            break;
        else
            std::cout << "Invalid command. Try again." << std::endl;
    }
    return 0;
}