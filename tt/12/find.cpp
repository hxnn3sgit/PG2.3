#include <iostream>
#include <filesystem>
#include <regex>

namespace fs = std::filesystem;

using std::cout, std::endl, std::string;

int main(int argc, char **argv) {
	if (argc != 2) {
		cout << "Kein Dateiname zur Überprüfung übergeben. Programm beenden...\n";
		exit(-1);
	}

	try {
		std::regex re(argv[1]);

		for (const auto &entry : fs::recursive_directory_iterator(fs::current_path())) {
			if (fs::is_regular_file(entry.path())) {
				std::smatch m;
				string filename = entry.path().filename().string();
				if (std::regex_match(filename, m, re)) {
					cout << entry.path() << endl;
				}
			}
		}
	} catch(const std::regex_error &e) {
		cout << "ungültiger Regex: " << e.what() << endl;
		return -1;
	}

	/*fs::path path_to_file = fs::current_path() / argv[1];

	if (fs::exists(path_to_file)) {
		cout << std::string(argv[1]) << endl;
	} else {
		cout << "find: '" << std::string(argv[1]) << "': Datei oder Verzeichnis nicht gefunden\n"; 
	}*/

	return 0;
}	
