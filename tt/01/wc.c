#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//WC OHNE ÜBERGABEPARAMETER NOCH FERTIG MACHEN


int wc_args(FILE *fptr) {
	int linecount = 0;
	char c;

	while (!feof(fptr)) {
		c = fgetc(fptr);
		if (c == '\n')
			linecount++;
	}
	return linecount;
}

int wc() {
	int lc = 0;
	char ch;
	char buffer[100];

	while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		    lc++;
	}

	return lc;
}

int main(int argc, char **argv) {
	setbuf(stdin, NULL);
	if (argc == 1) {
		int linecounter = 0;
		linecounter = wc();
		printf("\t%d\n", linecounter);
	} else if (argc == 2) {	
		FILE *fptr;
		char *filename = argv[1];
		fptr = fopen(filename, "r");

		if (fptr == NULL) {
			printf("Fehler beim Oeffnen der Datei. Programm beenden...\n");
			exit(0);
		}
		printf("%s hat %d Zeilen.\n", filename, wc_args(fptr));
		fclose(fptr);	
	} else {
		perror("Keine richtige Angabe des Dateinamen übergeben. Programm beenden...\n");
		exit(0);
	}

	return 0;
}
