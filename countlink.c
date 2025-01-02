#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int countlink(char * temp){
    struct stat bufferStat;
    stat(temp, &bufferStat);
    return bufferStat.st_nlink;
}

int main(){
    printf("The number of the link is : %d\n", countlink("."));
    return 0;
}