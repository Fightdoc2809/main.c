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
        if (!token){
            if (in != stdin) {
                fclose(in);
            }
            exit(EXIT_SUCCESS);
        }
        ausgabe = atoi(buffer);
        /*
        if (isalpha(*token) != 0) {
            fprintf(stderr, "Bitte nur Zahlen in Datei verwenden");
            exit(EXIT_FAILURE);
        }
        */
        ausgabe = ausgabe * 2;
        printf("%d\n", ausgabe);
    }





/*
    if(argc > 3 || argc == 1)
    {
        fprintf(stderr, "Usage: %s [<file>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if(argc == 2)
    {
        if (isalpha(*argv[1]) != 0) {
            in = fopen(argv[1], "r");
            if (!in) {
                perror(argv[0]);
                exit(EXIT_FAILURE);
            } else {
                fgets(buffer, 400, in);
                token = strtok(buffer, delimit);
                countnum = atoi(token);
                if (countnum == NULL) {
                    fprintf(stderr, "Please only use alphanumeric characters in %s\n", argv[1]);
                    exit(EXIT_FAILURE);
                }
                token = strtok(NULL, delimit);
                maxnum = atoi(token);
                if (maxnum == NULL) {
                    fprintf(stderr, "Please only use alphanumeric characters in %s\n", argv[1]);
                    exit(EXIT_FAILURE);
                }
            }
        }
        else {
            countnum = atoi(argv[1]);
        }
        srand(time(NULL));   // Initialization, should only be called once.
        for (int i = 0; i < countnum; i++) {
            ausgabe = rand() % maxnum;  // Returns a pseudo-random integer between 0 and RAND_MAX.
            printf("%d\n",ausgabe);
        }
    }

    if (argc == 3){
        countnum = atoi(argv[1]);
        maxnum = atoi(argv[2]);
        srand(time(NULL));   // Initialization, should only be called once.
        for (int i = 0; i < countnum; i++) {
            ausgabe = rand() % maxnum;  // Returns a pseudo-random integer between 0 and RAND_MAX.
            printf("%d\n",ausgabe);
        }
    }
    */
/* Here: Read from in with (e.g.) fgets(), ... */

}
