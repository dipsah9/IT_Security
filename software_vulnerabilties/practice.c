#include <stdio.h>
#include <string.h>

int main(){
    //strlcpy->prevents buffer overflow
    char str[3];
    strlcpy(str, "bye", 3);
    printf("%s\n", str);

    //vulnerabilities 'strcpy' will always overflow; 
    //destination buffer has size 3, but the source string has length 4 (including NUL byte)
    char str1[3];
    strcpy(str1, "bye");
    printf("%s\n", str1);

    return 0;
}