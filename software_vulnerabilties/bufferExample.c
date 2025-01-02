#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[8];  // Small buffer
    strcpy(buffer, input);  // Unsafe function
    printf("You entered: %s\n", buffer);
}

int main() {
    char input[128];
    printf("Enter a string: ");
    gets(input);  // Unsafe function
    vulnerable_function(input);
    return 0;
}

