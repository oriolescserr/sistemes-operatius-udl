#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[]) {

    char * path = argv[1];

    if (mkdir(path, 0700)){ // L'owner té tots els permisos, però el group i altres no
        perror("Error");
    } else {
        printf("Directory %s created\n", path);
    }
    
}
