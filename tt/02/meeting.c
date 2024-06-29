#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *vorname, *nachname;
} name;

void split_names(int size, char **argv, name *menschen) {
	for (int i = 1; i < size; ++i) {
		int name_len = strlen(argv[i]);
		for (int j = 0; j < (strlen(argv[i])); ++j) {
			if (argv[i][j] == ' ') {
			  	menschen[i-1].vorname = (char*)malloc(sizeof(char) * (j+1));
		  		strncpy(menschen[i-1].vorname, argv[i], j); //Vorname kopieren
				menschen[i-1].vorname[j] = '\0'; //nullbyte anfügen
				
				//Nachname kopieren:
				//Speicher reservieren
				//menschen[i-1].nachname = (char*)malloc(sizeof(char) * (name_len - j));
				//mit strncpy rüberkopieren von Stelle nach leerzeichen bis ende
				//argv[i] += (j+1);
				//strncpy(menschen[i-1].nachname, argv[i], (name_len-j));
				//argv[i] -= (j+1);
				menschen[i].nachname = strdup(&argv[i][j+1]);
				}
		}
	}
}
//andere lösung anstatt ganz argv zu übergeben?
void teilnehmer(name *menschen, int size, char **argv) {

	for (int i = 0; i < size-1; ++i) {
		
		if (strcmp(argv[i+1], "Brinesh Jain") == 0) { //warum geht des ned??
			printf("Debug print bj: %s\n", menschen[i].vorname);
			for (int j = 0; j < strlen(argv[i+1]); ++j) {
				printf("%c\n", argv[i+1][j]);
			}
			printf("\n");
			printf("Hallo bj\n");
		} else {
			printf("Hallo %s\n", menschen[i].vorname);
		}
	}
	
	for (int i = 0; i < size-1; ++i)
		printf("Hallo %s\n", menschen[i].nachname);
}

int main(int argc, char **argv) {
	if (argc > 1) {
		int size = argc-1;
		name *menschen = (name*)malloc(size * sizeof(name));
		split_names(size, argv, menschen);
		teilnehmer(menschen, size, argv);
		
		for (int i = 0; i < size-1; ++i) {
			free(menschen[i].vorname);
			free(menschen[i].nachname);
		}
		free(menschen);
	} else {
		perror("Keine Namen uebergeben. Programm beenden... \n");
		exit(EXIT_FAILURE);
	}
}
