#include <stdio.h>
#include <string.h>

// Simulating a vulnerable server processing heartbeat requests
void process_heartbeat(const char *request, int size) {
    char buffer[64]; // Fixed-size buffer
    int payload_length;

    // Read the payload length from the request
    payload_length = request[0]; // Assume the first byte indicates length

    // Simulate copying the payload into the response
    if (payload_length > 0 && payload_length <= size) {
        memcpy(buffer, request + 1, payload_length); // Vulnerable copy
        printf("Response: %.*s\n", payload_length, buffer);
    } else {
        printf("Invalid request\n");
    }
}

int main() {
    char malicious_request[] = {128, 'A', 'B', 'C'}; // Fake length: 128, payload: "ABC"
    printf("Sending malicious heartbeat request...\n");
    process_heartbeat(malicious_request, sizeof(malicious_request));
    return 0;
}
