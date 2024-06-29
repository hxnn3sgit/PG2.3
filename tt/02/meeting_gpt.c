#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *vorname;
    char *nachname;
} Name;

void split_names(int size, char **argv, Name *menschen) {
    for (int i = 1; i < size; ++i) {
        int name_len = strlen(argv[i]);
        for (int j = 0; j < name_len; ++j) {
            if (argv[i][j] == ' ') {
                menschen[i - 1].vorname = (char*)malloc((j + 1) * sizeof(char));
                if (menschen[i - 1].vorname == NULL) {
                    perror("Fehler bei Speicherzuweisung für Vorname.\n");
                    exit(EXIT_FAILURE);
                }
                strncpy(menschen[i - 1].vorname, argv[i], j);
                menschen[i - 1].vorname[j] = '\0';

                menschen[i - 1].nachname = (char*)malloc((name_len - j) * sizeof(char));
                if (menschen[i - 1].nachname == NULL) {
                    perror("Fehler bei Speicherzuweisung für Nachname.\n");
                    exit(EXIT_FAILURE);
                }
                strcpy(menschen[i - 1].nachname, &argv[i][j + 1]);
                break;
            }
        }
    }
}

void begruesse_teilnehmer(Name *menschen, int size) {
    for (int i = 0; i < size; ++i) {
        printf("Hallo %s\n", menschen[i].vorname);
    }
}

int main(int argc, char **argv) {
    if (argc > 1) {
        int size = argc;
        Name *menschen = (Name*)malloc((size - 1) * sizeof(Name));
        if (menschen == NULL) {
            perror("Fehler bei Speicherzuweisung für Menschen.\n");
            exit(EXIT_FAILURE);
        }
        split_names(size, argv, menschen);
        begruesse_teilnehmer(menschen, size - 1);

        // Speicher freigeben
        for (int i = 0; i < size - 1; ++i) {
            free(menschen[i].vorname);
            free(menschen[i].nachname);
        }
        free(menschen);
    } else {
        perror("Keine Namen übergeben. Programm beenden...\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
