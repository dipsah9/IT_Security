#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int count (char *input){
    return strlen(input);
}

int main(){
    int co = count("35072c1ae546350e0bfa7ab11d49dc6f129e72ccd57ec7eb671225bbd197c8f1");
    printf("%d\n", co);
    return 0;
}