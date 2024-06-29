#include <iostream>
#include "dyn_arr_normal.h"

using namespace std;

int main(int argc, char **argv) {

	dyn_arr my_array;

	for (int i = 1; i < argc; ++i) {
		cout << "atoi main, i: " << i << "; " << atoi(argv[i]) << endl;
		my_array.push(atoi(argv[i]));
	}

	std::cout << my_array << std::endl;
		
	return 0;
}
