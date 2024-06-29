#include <iostream>

using namespace std;

template<typename T>
void print_variable(T variable) {
	cout << __PRETTY_FUNCTION__ << endl;
	cout << variabl << endl;
}

int main() {

	int meine_zahl = 18;
	string papas_name = "Walter";

	//print_variable(meine_zahl);
	//print_variable(papas_name);

	return 0;
}
