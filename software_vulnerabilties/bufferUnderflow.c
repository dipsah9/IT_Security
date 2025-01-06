#include <stdio.h>
#include <string.h>

int main() {
    // Simulate sensitive data stored in memory
    char sensitive_data[] = "SecretPassword123";
    
    // A normal buffer to demonstrate the underflow
    char buffer[10];
    strcpy(buffer, "UserData");
    
    // Pointer to the buffer
    char *ptr = buffer;
    
    // Attempt to read memory before the buffer
    printf("Buffer contents: %s\n", buffer);
    printf("Accessing memory before the buffer...\n");
    
    // Access memory before the buffer to simulate underflow
    for (int i = -10; i < 0; i++) {
        printf("Memory at offset %d: %c\n", i, *(ptr + i));
    }
    
    return 0;
}
