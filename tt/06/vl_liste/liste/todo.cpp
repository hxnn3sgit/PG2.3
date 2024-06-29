#include "list.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout, std::cerr, std::endl, std::string;

const string todolist_name = ".todo";

int main(int argc, char **argv) {
	if (argc == 1) {
		cerr << "Wir brauchen ein Argument!" << endl;
		return -1;
	}

	pg2::list todos;
	std::ifstream in(todolist_name);
	string line;
	while (getline(in, line))
		todos.append(line);
	in.close();

	string command = argv[1];
	bool contents_changed = false;
	if (command == "list") {
		todos.start();
		int i = 0;
		while (todos.at_valid_position()) {
			cout << ++i << ".) " << todos.current_value() << endl;
			todos.next();
		}
	}
	else if (command == "done" || command == "remove") {
		if (argc != 3) {
			cerr << "Bitte genau eine Nummer zum entfernen angeben!" << endl;
			return -1;
		}
		int to_remove = atoi(argv[2]);
		todos.start();
		for (int i = 1; i < to_remove; ++i)
			todos.next();	
		todos.remove_current();
		contents_changed = true;
	}
	else {
		std::ostringstream oss;
		oss << argv[1];
		for (int i = 2; i < argc; ++i)
			oss << " " << argv[i];
		todos.append(oss.str());
		contents_changed = true;
	}

	if (contents_changed) {
		std::ofstream out(todolist_name);
		todos.start();
		while (todos.at_valid_position()) {
			out << todos.current_value() << endl;
			todos.next();
		}
	}
}

