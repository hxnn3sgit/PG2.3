#include <iostream>

using std::cout, std::endl;

int main(int argc, char **argv) {
	int zahl1, zahl2, basis;

	auto add_two_numbers_and_base = [&basis] (int zahl1, int zahl2) {
		return (basis + (zahl1 + zahl2));
	};

	if (argc == 4) {
		zahl1 = std::stoi(argv[1]);
		zahl2 = std::stoi(argv[2]);
		basis = std::stoi(argv[3]);

		cout << add_two_numbers_and_base(zahl1, zahl2) << endl;
	} else {
		
		zahl1 = 3, zahl2 = 4, basis = 5;

		cout << add_two_numbers_and_base(zahl1, zahl2) << endl;
	}
	
	return 0;
}
