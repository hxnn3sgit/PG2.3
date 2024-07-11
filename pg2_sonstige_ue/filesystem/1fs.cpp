#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout, std::endl;

int main() {
	
	fs::path p{"."};

	for (const auto &entry : fs::directory_iterator(p)) {
		cout << entry.path().string() << endl;
		if (entry.is_directory())
			cout << "Verzeichnis: ";
		else if (entry.is_regular_file())
			continue;

	}	
		
	return 0;
}
