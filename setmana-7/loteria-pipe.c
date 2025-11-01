#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

#define NUM_FILLS 5  // Nombre de processos fills

int fd[2];  // Array per als descriptors de fitxer de la pipe

int main() {
    pid_t pid;
    int i, status;
    int bitllet = 0;
    
    // Creació de la pipe
    // fd[0] - extrem de lectura (read)
    // fd[1] - extrem d'escriptura (write)
    int r = pipe(fd);

    if (r == -1) {
        perror("Error en crear la pipe");
        exit(1);
    }

    // Creació dels processos fills
    for (i = 0; i < NUM_FILLS; i++) {
             = fork();
        if (pid < 0) {
            perror("Error en el fork");
            exit(1);
        } else if (pid == 0) {  // Codi que executa cada fill
            srand(time(NULL) ^ getpid());
            int num = rand() % 10;  // Genera un número aleatori

            close(fd[0]);  // Els fills no llegeixen, tanquem extrem de lectura
            write(fd[1], &num, sizeof(num));  // Escriu el número a la pipe
            close(fd[1]);  // No cal, però és una bona pràctica

            printf("Fill PID %d genera %d\n", getpid(), num);
            exit(0);  // El fill acaba aquí
        }
    }

    // Codi que executa només el pare
    for (i = 0; i < NUM_FILLS; i++) {
        pid_t child_pid = waitpid(-1, &status, 0);  // Espera qualsevol procés fill
        if (WIFEXITED(status)) {  // Si el fill ha acabat correctament
            close(fd[1]);  // El pare no escriu, tanquem extrem d'escriptura
            int num;
            read(fd[0], &num, sizeof(num));  // Llegeix un número de la pipe
            printf("Pare recull fill PID %d amb %d\n", child_pid, num);
            bitllet = bitllet * 10 + num;  // Construeix el número de bitllet
        }
    }

    close(fd[0]);  // Tanca l'extrem de lectura
    printf("Bitllet final del pare: %05d\n", bitllet);  // Mostra el bitllet final
    return 0;
}