/**
 * main.cpp
 * Author: Your Name
 * Description: This is the driver file for testing the EncryptedString class. 
 * It includes tests with hardcoded strings and 
 * provides an option for the user to input their own strings for encryption and decryption. 
 * The program uses input validation to ensure only valid choices are processed.
 */

#include <iostream>
#include "EncryptedString.h"

using namespace std;

/**
 * Function: testHardcodedStrings
 * Description: Tests the EncryptedString class with predefined hardcoded strings.
 * Parameters: None
 * Returns: void
 */
void testHardcodedStrings() {
    // Test with hardcoded strings
    string testStrings[] = {
        "",
        "abcd",
        "ABcd",
        "ABCD",
        "Hi Mom ",
        "Hi Mom !%#$%^&"
    };

    for(const string& testString : testStrings) {
        EncryptedString encrypted(testString);
        cout << "Original string: \"" << testString << "\"" << endl;
        cout << "Encrypted string: \"" << encrypted.getEncrypted() << "\"" << endl;
        cout << "Decrypted string: \"" << encrypted.get() << "\"" << endl;
        cout << "Ignored characters: ";
        for (char ch : testString) {
            if (!isalpha(ch) && ch != ' ') {
                cout << ch;
            }
        }
        cout << endl << endl;
    }
}

/**
 * Function: userInputMode
 * Description: Prompts the user to enter a string, 
 * then encrypts and decrypts the string using the EncryptedString class.
 * Parameters: None
 * Returns: void
 */

void userInputMode() {
    string userInput;
    cout << "Enter a string to encrypt: ";
    getline(cin, userInput);

    EncryptedString userEncrypted(userInput);
    cout << "Original string: \"" << userInput << "\"" << endl;
    cout << "Encrypted string: \"" << userEncrypted.getEncrypted() << "\"" << endl;
    cout << "Decrypted string: \"" << userEncrypted.get() << "\"" << endl;
    cout << "Ignored characters: ";
    for (char ch : userInput) {
        if (!isalpha(ch) && ch != ' ') {
            cout << ch;
        }
    }
    cout << endl;
}

int main() {
    testHardcodedStrings();

    char choice;
    do {
        cout << "Do you want to enter a string to encrypt? (Y/N): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer by cin

        // Input validation
        if (choice == 'Y' || choice == 'y') {
            userInputMode();
        } else if (choice != 'N' && choice != 'n') {
            cout << "Invalid choice. Please enter 'Y' or 'N'." << endl;
        }
    } while (choice != 'N' && choice != 'n');

    cout << "Program terminated." << endl;
    return 0;
}
