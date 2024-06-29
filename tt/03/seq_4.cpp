#include <iostream>
#include <fstream>

using namespace std;

void seq(int start, int end);
void seq(int start, int step, int end);

void print_help() {
	string line;

	ifstream in("seq_help");

	while (in >> line) {
		cout << line;
	}		
}

int main(int argc, char **argv) {
		if (argc == 3) {
			int start = atoi(argv[1]);
			int end = atoi(argv[2]);
			seq(start, end);
		} else if (argc == 4) {
			int start = atoi(argv[1]);
			int step = atoi(argv[2]);
			int end = atoi (argv[3]);
			seq(start, step, end);
		} else {
			cout << "Falschen Argumente Uebergeben. Proramm beenden\n";
			print_help();	
			return(EXIT_FAILURE);
		}

		return 0;
}

void seq(int start, int end) {
	for (int i = start; i <= end; ++i) 
			cout << i << endl;
}

void seq(int start, int step, int end) {
	for (int i = start; i <= end; i += step)
			cout << i << endl;
}
