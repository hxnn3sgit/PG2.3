#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void cat(const string &filename) {
	ifstream in(filename);
	string line;
	while (getline(in, line))
		cout << line << endl;
}

void cat_with_linenr(const string &filename) {
	ifstream in(filename);
	string line;
	int counter = 1;
	while (getline(in, line)) { 
		cout << setw(6) << right << counter << "  "  << line << endl;
		counter++;
	}
}

void cat(int argc, char **args) {

}

void cat_without_linenr(char **args) {

}

void more_cat_with_linenr(char **args) {

}

int main(int argc, char **argv) {
	if (argc == 2) {
		cat(string(argv[1]));
	} else if (argc == 3) {
		if (string(argv[1]) == "-n"){
			cat_with_linenr(string(argv[2]));
		} else if(string(argv[2]) == "-n") {
			cat_with_linenr(string(argv[1]));
		} else {
			cerr << "Falsche Option uebergeben. Mit '-n' aufrufen für Zeilennummern\n";
			return -1;
		}
	} /*else if (argc >= 3) {
		if (string(argv[1]) == "-n" || string(argv[argc-1]) == "-n") {
			more_cat_with_linenr(argv);
		} else {
			cat_without_linenr(argv);
		}
	}*/ else {
		cerr << "Falsche oder keine Datei angegeben\n";
		return -1;
	}

	return 0;
}
