#include <iostream>
#include <filesystem>

using std::cout, std::endl;

namespace fs = std::filesystem;

int main(int argc, char **argv) {
	fs::path current_path = fs::current_path();

	
	for (const auto &thing : fs::directory_iterator(current_path) ) {
		if (thing.is_regular_file()) {
			
			cout << thing.file_size() << " ";
			cout << thing.path().filename().string() << " ";
		}
		cout << endl;
	}

	cout << endl;
	
	return 0;
}