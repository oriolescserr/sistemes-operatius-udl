#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

char *color_blue   = "\033[01;34m";
char *color_end    = "\033[00m";
char *color_red    = "\033[01;31m";
char *color_green  = "\033[01;32m";

char *args[] = {"jugador", "jugador", NULL};

// Funcionalitat per gestionar l'alarma (SIGALRM)
void alarma();
void alarma(){
    raise(SIGUSR1);
}

int main(int argc, char *argv[]) {

    int fd[2];
    char s[100];
    int *pids;
    int tempsPartida, numJugadors;
    char *clau;

    if (argc < 4) {
        fprintf(stderr, "Ús: %s tempsPartida numJugadors clau\n", argv[0]);
        exit(1);
    }

    //TODO: Llegir arguments
    tempsPartida = atoi(argv[1]);
    numJugadors = atoi(argv[2]);
    clau = argv[3];
    
    //TODO: Definir l'acció per a la senyal SIGALRM
    signal(SIGALRM, alarma);

    sprintf(s, "Inici del Room Escape [%d] (%d segons)\n", getpid(), tempsPartida);
    write(1, s, strlen(s));

    sprintf(s, "--- Entren %d jugadors a la sala\n", numJugadors);
    write(1, s, strlen(s));

    sprintf(s, "--- La clau secreta és: %s\n", clau);
    write(1, s, strlen(s));

    /* TODO 2: Crear processos fills (jugadors) amb fork() */
    for(int i = 0; i < numJugadors; i++){
        pids[i] = fork();
 
        else {
            execvp(args[0], args);
        }
    }

    alarm(tempsPartida);

    //TODO 3: Esperar respostes dels jugadors mitjançant pipe
    // Si algun jugador encerta la clau, mostrar missatge de victòria i acabar


    //TODO 5: Gestionar finalització en funció de si s'ha encertat la clau o ha sonat l'alarma

    // TODO 6: Mostrar missatge final segons resultat

    exit(0);
}