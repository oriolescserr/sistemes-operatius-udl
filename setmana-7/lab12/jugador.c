#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void end_handler(); // Declara la funció
void end_handler(){ // La implementa
    exit(0);
}


int main(int argc, char *argv[]) {

    signal(SIGUSR1, end_handler);
    
    //Els misstges de log no han d'anar a stdout sinó a stderr
    char s[100];
    sprintf(s, "--- Jugador %d ha entrat a la sala\n", getpid());
    write(2, s, strlen(s)); // Canviar 1 per 2

    int n = 4;
    char pass[n];
    // Després d’això, totes les crides a rand() usaran aquest estat intern
    srand(time(NULL) + getpid()); // Suma la hora actual i li afegeix el pid perquè sempre tinguin nombres diferents

    // Generar 4 caràcters aleatoris (per ex. 'A' + rand() % 26)
    while(1){
        for(int i = 0; i < n; i++){
            pass[i] = 'A' + rand() % 26;
        }
        write(1, pass, n);
    }

    sprintf(s, "--- La clau generada pel jugador %d és: %s\n", getpid(), pass);
    write(1, s, strlen(s));

    return 0;
}