#include <stdlib.h>   // Serveix per constants com EXIT_SUCCESS o EXIT_FAILURE
#include <stdio.h>    // Serveix per printf, perror, etc. (funcions d’impressió)
#include <unistd.h>   // Conté funcions del sistema com execvp() o getuid()
#include <sys/types.h> // Defineix tipus com uid_t (no és necessari però es posa per costum)

/*
 * ohmy_sudo.c
 * Aquest programa agafa una comanda (per exemple, "ls", "whoami", "cat fitxer.txt")
 * i l’executa directament.
 *
 * És com fer "sudo", però sense cap seguretat ni comprovació.
 * Si el fitxer és propietat de root i té el bit setuid activat,
 * la comanda que s’executi tindrà permisos de root.
 * ⚠️ Això és només per aprendre com funciona execvp, no per usar-ho realment.
 */

int main(int argc, char *argv[]) {

    /*
     * execvp() és una funció que substitueix el programa actual
     * (aquest fitxer .c) pel programa que li diem.
     *
     * Exemple:
     *   ./ohmy_sudo ls -l
     * Això executarà la comanda "ls -l"
     *
     * execvp té dos paràmetres:
     *   1️⃣ argv[1] → és el nom del programa a executar ("ls", "cat", "whoami"...)
     *   2️⃣ &argv[1] → és la llista d’arguments (on argv[1] és el nom del programa
     *       i argv[2], argv[3]... són els arguments addicionals)
     *
     * execvp buscarà el programa dins del PATH (com faria el terminal)
     * i el substituirà pel procés actual.
     *
     * IMPORTANT:
     *   - Si execvp funciona bé, NO torna mai: el nostre programa desapareix i
     *     es converteix en el que hem demanat executar.
     *   - Si hi ha un error (per exemple, el programa no existeix),
     *     execvp retorna i podem mostrar un missatge d’error.
     */
    
    execvp(argv[1], &argv[1]);

    /*
     * Si arribem aquí, vol dir que execvp ha fallat.
     * Això passa si la comanda no existeix o no es pot executar.
     */
    perror("Error executant la comanda");
    return EXIT_FAILURE;
}
