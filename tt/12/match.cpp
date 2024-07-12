#include <iostream>
#include <regex>
#include <string>

using std::cout, std::endl, std::string;

int main(int argc, char **argv) {
	if (argc != 2 ) {
		cout << "Kein regex übergeben. Programm beenden..." << endl;
		exit(-1);
	}

	std::string expr(argv[1]);
	std::regex re {argv[1]};
	string line;
	
	while(std::getline(std::cin, line)){
		std::smatch m;
		if (regex_match(line, m, re))
			cout << line << endl;
	}

	return 0;
}
