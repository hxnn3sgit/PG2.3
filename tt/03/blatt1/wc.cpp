#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
//nur lesen-> const string reference:

int wc(const string &filename) {
	int words = 0;
	
	ifstream in(filename);

	if (!in.is_open()) {
		cout << "Datei konnte nicht geöffnet werden. Programm beenden...\n";
		return(EXIT_FAILURE);
	}
	string line;
	while (in >> line) {
		words++;
	}

	return words;
}

int lc(const string &filename) {
	int lines = 0;

	ifstream in(filename);

	if (!in.is_open()) {
		cerr << "Datei konnte nicht geoeffnet werden. Programm beenden...\n";
		return -1;
	}
	char ch;
	while ( in.get(ch)) {
		if (ch == '\n')
			lines++;
	}

	return lines;
}

int cc( string filename) {
	int chars = 0;

	ifstream in(filename);

	if (!in.is_open()) {
		cerr << "Datei konnte nicht geoeffnet werden. Programm beenden...\n";
		return -1;
	}
	char ch;

	while (in.get(ch)) {
		if (isalpha(ch))
			chars++;
	}

	return chars;
}

void wc_terminal() {
	char ch;
	while(cin.get(ch)) {
		cout << ch;
	}
}

int main(int argc, char **argv) {
	
	if (argc == 1) {
		wc_terminal();
	} else if (argc == 2) {
		string filename = argv[1];
		cout << setw(3) << wc(filename) << setw(3) << " " << lc(filename) << setw(3) << " " << cc(filename) << setw(3) << " " << filename << endl;

	} else if (argc > 2) {
		int names = argc-1;
		string *filenames = (string*)malloc(names * sizeof(
		for (int i = 0; i < argc; ++i) {
			
		}

	} else {
		std::cerr << "Falsche Argumente uebergeben. Programm beenden...\n";
		return(-1);
	}


	return 0;
}
