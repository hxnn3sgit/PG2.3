#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using std::cout, std::endl, std::string;

void counting_from_cin() {
	string line;
	int line_counter = 0, char_counter = 0;
	while (std::getline(std::cin, line)) {
		++line_counter;
		char_counter += line.length();
	}
	cout << "\t" << line_counter << "\t" << char_counter << endl;
}

int main(int argc, char **argv) {
	if (argc == 1 && strcmp(argv[1]), "-l" && strcmp(argv[1], "-c")) {
		counting_from_cin();
	} else if (argc >= 1) {
		string arg = argv[2];
		if (arg == "-l" || arg == "-c") {
			arg = argv[3];
			if (arg == "-c" || arg == "-l") { //count lines and chars
				cout << 1 << endl;
		}
	}

	return 0;
}
