#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>

extern errno;

int main(int argc, char *argv[]) {
    struct stat st;
    if (argc == 2) {
        char * path = argv[1];
        if (stat(path, &st) == -1) {
            perror("Error");
        } else {
            printf("The directory %s exists\n", path);
        } 
    }
    return 0;
}
            
            
