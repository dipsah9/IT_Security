#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *plaintext = "NEVERTRUSTINSECURITYBYOBSCURITY";
    char *ciphertext = "ARIREGEHFGVAFRPHEVGLOLBOFPHEVGL";

    char *result = malloc(sizeof(plaintext));
    int len = strlen(plaintext);

    for(int i = 0; i < len; i++){
        result[i] = (ciphertext[i]) -  (plaintext[i]) ;
        printf("%d\n", result[i]);
    }


    return 0;
}