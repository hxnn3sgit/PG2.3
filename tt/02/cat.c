#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void cat(const char *fn1, const char *fn2) {
	FILE *f;
	int ch;
	f = fopen(fn1, "r");

	//Check, if file opened correctly
	if (f == NULL) {
		perror("Datei konnte nicht geoeffnet werden. Programm beenden...\n");
		exit(EXIT_FAILURE);
	}
	
	//print characters
	while ( (ch = fgetc(f)) != EOF) {
		printf("%c", ch);
	}
	fclose(f);

	f = fopen(fn2, "r");
	
	//check again
	if (f == NULL) {
		perror("Datei konnte nicht geoeffnet werden. Programm beenden...\n");
		exit(EXIT_FAILURE);
	}
	
	//print characters^
	while ( (ch = fgetc(f)) != EOF) {
		printf("%c", ch);
	}

	fclose(f);
}

void print() {
	//int because of fgetc function
	int ch;
	while ( (ch = fgetc(stdin)) != EOF) {
		printf("%c", ch);
	}
}

int main(int argc, char **argv) {
	if (argc == 3) {
		char *filename1 = argv[1];
		char *filename2 = argv[2];
		cat(filename1, filename2);
	} else if (argc == 1) {
		print();
	} else {
		perror("Falsche Uebergabeparamenter. Programm beenden...\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
