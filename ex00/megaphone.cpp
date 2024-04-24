#include <iostream>

int main(int argc, char **argv) {
    if(argc < 2 ) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        std::string word = argv[i];
        for (size_t j = 0; j < word.length(); j++) {
            word[j] = std::toupper(word[j]);
        }
        std::cout << word << " ";
    }
    std::cout << std::endl;
    return 0;
}
