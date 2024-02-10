#include <iostream>
// #include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>

std::string generatePassword() {
    const std::string UpperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string LowerCase = "abcdefghijklmnopqrstuvwxyz";
    const std::string Symbols = "!@#$%^&*()_-+=[]{}|;:',.<>?`";
    const std::string Numbers = "0123456789";
    const std::string AllChars = UpperCase + LowerCase + Symbols + Numbers;
    int length = std::rand() % 8 + 12; // range is [12, 20)

    std::string password;   

    // Ensure at least one character from each category in the first four characters
    password += UpperCase[rand() % UpperCase.length()];
    password += LowerCase[rand() % LowerCase.length()];
    password += Symbols[rand() % Symbols.length()];
    password += Numbers[rand() % Numbers.length()];

    // Fill the rest of the password
    for (int i = 4; i < length; ++i) {
        password += AllChars[rand() % AllChars.length()];
    }

    // Swap characters to ensure a mix of characters
    for (size_t i = 0; i < 6; ++i) {
        size_t rand_index = std::rand() % (length - 5); // [6, length)
        std::swap(password[i], password[rand_index]); // swap 
    }
    
    return password; // return generated password
}

void writeToFile(const std::string& filename, int count) {
    std::ofstream write(filename, std::ios::out);
    if (write.is_open()) {
        while (count) {
            write << generatePassword() << "\n"; // Generates and writes to a file
            --count;
        }
        write.close();
        std::cout << "Passwords written to 'generatedpassword.txt' successfully." << std::endl;
    } else {
        std::cerr << "Unable to open the file for writing." << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed with the current time
    int count = 30; // Set count to 30 for generating 30 passwords
    writeToFile("generatedPassword.txt", count);

    return 0;
}
