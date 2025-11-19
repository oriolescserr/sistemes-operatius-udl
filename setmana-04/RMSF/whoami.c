#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    uid_t uid = getuid();
    struct passwd *pwd;

    if((pwd = getpwuid(uid)) != NULL){
        printf("\nEl nom de l'usuari és: %s and id %d\n", pwd->pw_name, uid);
    } else {
        printf("\nEl usuari amb uid: %d no esta en el sistema\n", uid);
    }
}