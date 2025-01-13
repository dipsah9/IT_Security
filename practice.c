#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//NOte: To check the vulnerability just enter the username: frank OR 1=1 and password: anything

// Function to simulate login verification
bool verifyLogin(const char *username, const char *password) {
    // Correct credentials (hardcoded for demonstration)
    const char *correctUsername = "frank";
    const char *correctPassword = "1234";

    // Insecure condition that mimics SQL Injection vulnerability
    if ((strcmp(username, correctUsername) == 0 && strcmp(password, correctPassword) == 0) ||
        strstr(username, "OR 1=1")) {
        return true;  
    }

    return false;  
}

int main() {
    char username[100];
    char password[100];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  

    // Check login
    if (verifyLogin(username, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}

