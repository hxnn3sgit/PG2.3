#include <png++/png.hpp>
#include <iostream>
#include <cmath>
#include "complex-number.h"

using namespace std;
using namespace png;

int main(int argc, char **argv) {
	if (argc != 4) {
		print_how_to_use();
		exit(-1);
	}

	float w = atof(argv[1]);
	float h = atof(argv[2]);
	string filename = argv[3];
	
	return 0;
}
