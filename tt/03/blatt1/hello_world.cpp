#include <iostream>

using std::cout, std::endl;

int main(int argc, char **argv) {

	cout << "Hello World" << endl;

	for (int i = 1; i < argc; ++i)
		cout << argv[i] << endl;


	return EXIT_SUCCESS;
}
