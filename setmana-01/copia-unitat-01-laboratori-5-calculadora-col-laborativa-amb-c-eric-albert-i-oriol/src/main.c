#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "calc.h"  

void mostrar_ajuda() {
    printf("Ús: calc [OPCIONS]\n");
    printf("Opcions:\n");
    printf("  -s, --suma NUM1 NUM2        Suma de dos números\n");
    printf("  -r, --resta NUM1 NUM2       Resta de dos números\n");
    printf("  -m, --multiplicacio NUM1 NUM2 Multiplicació de dos números\n");
    printf("  -d, --divisio NUM1 NUM2     Divisió de dos números\n");
    printf("  -q, --arrel NUM             Arrel quadrada d'un número\n");
    printf("  -p, --potencia NUM BASE     Potència (NUM^BASE)\n");
    printf("  -h, --help                  Mostra aquest missatge d'ajuda\n");
}

int main(int argc, char *argv[]) {
    int opcio;
    double num1 = 0, num2 = 0;
    
    // Definim les opcions llargues
    static struct option long_options[] = {
        {"suma", required_argument, 0, 's'},
        {"resta", required_argument, 0, 'r'},
        {"multiplicacio", required_argument, 0, 'm'},
        {"divisio", required_argument, 0, 'd'},
        {"arrel", required_argument, 0, 'q'},
        {"potencia", required_argument, 0, 'p'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    if (argc < 2) {
        mostrar_ajuda();
        return 1;
    }

    // Utilitzem getopt per capturar els arguments
    while ((opcio = getopt_long(argc, argv, "s:r:m:d:q:p:h", long_options, NULL)) != -1) {
        switch (opcio) {
            case 's':
                if (argc >= optind + 1) {
                    num1 = atof(optarg);
                    num2 = atof(argv[optind]);
                    printf("Resultat de la suma: %.2f\n", suma(num1, num2));
                    //printf("Not implemented yet!\n");
                } else {
                    printf("Falten arguments per a la suma.\n");
                    return 1;
                }
                break;

            case 'r':
                if (argc >= optind + 1) {
                    num1 = atof(optarg);
                    num2 = atof(argv[optind]);
                    printf("Resultat de la resta: %.2f\n", resta(num1, num2));
                    //printf("Not implemented yet!\n");
                } else {
                    printf("Falten arguments per a la resta.\n");
                    return 1;
                }
                break;

            case 'm':
                if (argc >= optind + 1) {
                    num1 = atof(optarg);
                    num2 = atof(argv[optind]);
                    printf("Resultat de la multiplicació: %.2f\n", multiplicacio(num1, num2));
                    //printf("Not implemented yet!\n");
                } else {
                    printf("Falten arguments per a la multiplicació.\n");
                    return 1;
                }
                break;

            case 'd':
                if (argc >= optind + 1) {
                    num1 = atof(optarg);
                    num2 = atof(argv[optind]);
                    if (num2 == 0) {
                        printf("No es pot dividir per zero!\n");
                        return 1;
                    }
                    printf("Resultat de la divisió: %.2f\n", divisio(num1, num2));
                    //printf("Not implemented yet!\n");
                } else {
                    printf("Falten arguments per a la divisió.\n");
                    return 1;
                }
                break;

            case 'q':
                num1 = atof(optarg);
                if (num1 < 0) {
                    printf("No es pot calcular l'arrel quadrada d'un número negatiu!\n");
                    return 1;
                }
                printf("Resultat de l'arrel quadrada: %.2f\n", arrel(num1));
                //printf("Not implemented yet!\n");
                break;

            case 'p':
                if (argc >= optind + 1) {
                    num1 = atof(optarg);
                    num2 = atof(argv[optind]);
                    printf("Resultat de la potència: %.2f\n", potencia(num1, num2));
                    //printf("Not implemented yet!\n");
                } else {
                    printf("Falten arguments per a la potència.\n");
                    return 1;
                }
                break;

            case 'h':
                mostrar_ajuda();
                return 0;

            default:
                mostrar_ajuda();
                return 1;
        }
    }

    return 0;
}
