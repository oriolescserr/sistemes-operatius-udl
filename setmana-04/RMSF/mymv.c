#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

extern errno;

int main(int argc, char *argv[]) {
    char * path = argv[1];
    char * to = argv[2];
    if(rename(path, to)==-1){
        perror("Error");
        return -1;
    } else {
        printf("File %s renamed to %s\n", path, to);
    }
    return 0;
}
