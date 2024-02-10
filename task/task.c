#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

void generatePassword(char *password) {
    const char UpperCase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char LowerCase[] = "abcdefghijklmnopqrstuvwxyz";
    const char Symbols[] = "!@#$%^&*()_-+=[]{}|;:',.<>?`";
    const char Numbers[] = "0123456789";
    const char AllChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_-+=[]{}|;:',.<>?`0123456789";

    int length = rand() % 8 + 12; // range is [12, 20)

    // Ensure at least one character from each category in the first four characters
    password[0] = UpperCase[rand() % (sizeof(UpperCase) - 1)];
    password[1] = LowerCase[rand() % (sizeof(LowerCase) - 1)];
    password[2] = Symbols[rand() % (sizeof(Symbols) - 1)];
    password[3] = Numbers[rand() % (sizeof(Numbers) - 1)];

    // Fill the rest of the password
    for (int i = 4; i < length; ++i) {
        password[i] = AllChars[rand() % (sizeof(UpperCase) + sizeof(LowerCase) + sizeof(Symbols) + sizeof(Numbers) - 4)];
    }

    // Swap characters to ensure a mix of characters
    for (size_t i = 0; i < 6; ++i) {
        size_t rand_index = rand() % (length - 5) + 4; // [4, length)
        char temp = password[i];
        password[i] = password[rand_index];
        password[rand_index] = temp; // swap
    }

    password[length] = '\0'; // Null-terminate the string
}

void writeToFile(const char *filename, int count) {
    FILE *write = fopen(filename, "w");
    if (write != NULL) {
        while (count) {
            char password[MAX_PASSWORD_LENGTH + 1]; // +1 for null terminator
            generatePassword(password);
            fprintf(write, "%s\n", password); // Generates and writes to a file
            --count;
        }
        printf("Passwords written to 'generatedpassword.txt' successfully.\n");
        fclose(write);
    } else {
        fprintf(stderr, "Unable to open the file for writing.\n");
    }
}

int main() {
    srand((unsigned)time(NULL)); // Seed with the current time
    int count = 30; // Set count to 30 for generating 30 passwords
    writeToFile("generatedPassword.txt", count);

    return 0;
}
