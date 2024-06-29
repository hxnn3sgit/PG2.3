#include <iostream>
#include "k19_5.h"

using namespace std;

int main(int argc, char **argv) {
	double x = atof(argv[1]);
	double y = atof(argv[2]);
	double z = atof(argv[3]);

	Point3D p(x, y, z);

	cout << p << endl;

	return 0;
}
