#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    //declaration
    FILE *in = stdin;
    int ausgabe;
    char buffer[400];
    char delimit[] = ",:;\n";
    char *token;

    //Abfrage bei mehr als 2 Argumenten
    if (argc > 2) {
        fprintf(stderr, "Bitte Maximal 2 Argumente angeben");
        exit(EXIT_FAILURE);
    }

    //Abfrage bei 2 Argumenten
    if (argc == 2) {
        //Datei wird geöffnet und in "in" gespeichert
        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    //Eingabe wird aufgesplitet
    while (fgets(buffer, 400, in)) {
        token = strtok(buffer, delimit);
        if (!token) {
            if (in != stdin) {
                fclose(in);
            }
            exit(EXIT_SUCCESS);
        }

        //Eingabe wird verdoppelt und ausgegeben
        ausgabe = atoi(buffer);
        ausgabe = ausgabe * 2;
        printf("%d\n", ausgabe);
    }
    if (in != stdin) {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}
