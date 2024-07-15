#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using std::cout, std::endl, std::string;

struct no_arguments : public std::exception {
	const char* what() const noexcept override {
		return "no filenames were given.\n";
	}
};

struct file_not_opened :public std::exception {
	const char* what() const noexcept override {
		return "file couldn´t be opened.\n";
	}
};

void printing_cin() {
	string line;
	while(getline(std::cin, line))
		cout << line << endl;
}

void printing_heads(int argc, char **argv, int n = 10) {
	for (int i = 1; i < argc; ++i) {
		std::ifstream out;
		out.open(string(argv[i]));
		if (out.is_open()) {
			for (int i = 0; i < n; ++i) {
				string line;
				std::getline(out, line);
				cout << line << endl;
			}
		} else
			throw file_not_opened();
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		printing_cin();
	} else if (argc > 1) {
		string arg = argv[argc-2];
		if (arg == "-n") {
			int n = std::stoi(argv[argc-1]);
			printing_heads(argc, argv, n);
		} else
			printing_heads(argc, argv);
	}

	return 0;
}