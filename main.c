#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    FILE *in = stdin;
    int num, ausgabe;
    char buffer[400];
    char delimit[] = ",:;\n";
    char *token;

    if (argc > 2) {
        fprintf(stderr, "Bitte Maximal 2 Argumente angeben");
        exit(EXIT_FAILURE);
    }

    if (argc == 2) {

        in = fopen(argv[1], "r");
        if (!in) {
            perror(argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    while (fgets(buffer, 400, in)) {
        token = strtok(buffer, delimit);
        if (!token) {
            if (in != stdin) {
                fclose(in);
            }
            exit(EXIT_SUCCESS);
        }
        ausgabe = atoi(buffer);
        ausgabe = ausgabe * 2;
        printf("%d\n", ausgabe);
    }
    if (in != stdin) {
        fclose(in);
    }
    exit(EXIT_SUCCESS);
}
