#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define TRASH ".trash"
#define PATH "/home/oriolescserr"

int main(int argc, char *argv[]) {
    
    char * path2; // == NULL
    path2 = malloc((strlen(PATH) + strlen(TRASH) + 1 + 1) * sizeof(char));
    strcpy(path2, PATH);
    strcat(path2, "/");
    strcat(path2, TRASH);

    printf("The value of the path is: %s\n", path2);

    return 0;

}


