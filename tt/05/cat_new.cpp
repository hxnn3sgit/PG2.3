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

void cat(const unsigned int n_pos, char **args, const int argc) {
	int line_nr = 1;
	for (int i = 1; i < argc; ++i) {
		if (i != n_pos) {
			ifstream in(args[i]);
			string line;
			while (getline(in, line)) {
				cout << setw(6) << right << line_nr << "  " << line << endl;
				line_nr++;
			}
			in.close();		
		}	
	}
}

void cat(const int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		ifstream in(argv[i]);
		string line;
		while (getline(in, line))
			cout << line << endl;
		in.close();
	}
}

int main(int argc, char **argv) {
	if (argc == 2) {
		cat(string(argv[1]));
	} else if (argc >= 3) {
		unsigned int n_position = 0;
		for (int i = 1; i < argc; ++i) { //get position of n
			if (string(argv[i]) == "-n")
				n_position = i;  //schauen, ob das die richtige stelle ist
		}

		if (n_position != 0) {
		   cat(n_position, argv, argc); //mit zeile ausgeben
		} else if (n_position == 0) {
		   //ohne zeile ausgeben
		   cat(argc, argv);
		} else {
			cerr << "Falsche Option uebergeben. Mit '-n' aufrufen für Zeilennummern\n";
			return -1;
		}
	} else {
		cerr << "Falsche oder keine Datei angegeben\n";
		return -1;
	}

	return 0;
}
