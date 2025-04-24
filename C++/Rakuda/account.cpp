#include <iostream>
#include <string>

unsigned long myHash(const std::string& str) {
    unsigned long hash = 0;
    for (char c : str) {
        hash = (hash * 31) ^ c;  // Multiply by prime & XOR with character
    }
    return hash;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::cout << "Custom Hash: " << myHash(input) << std::endl;
    return 0;
}
//sonu==3323717