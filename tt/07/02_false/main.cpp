#include "complex-number.h"
#include <iostream>
#include <png++/png.hpp>

using namespace std;

int main() {
	complex_number complex_1 = 1;	
	complex_number complex_2(1, 1);

	cout << complex_1 << endl;
	cout << complex_2 << endl;
	//cout << complex_number(1,2) + complex_number(2,3) << endl;
	cout << 1 + complex_number(1,3) << endl;
	//cout << complex_2 + complex_number(4, 5) << endl;
	return 0;
}
