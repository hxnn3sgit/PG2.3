#include <png++/png.hpp>
#include <iostream>
#include <cmath>
#include "complex-number.h"

using namespace std;
using namespace png;

/*bool is_valid(complex_number &number, image<rgb_pixel> result) {
	int x = round(number.realteil());
	int y = round(number.imagteil());

	if (x >= 0 && x < result.get_width() && y >=  0 && y < result.get_height()) {
		return true;
	} else
		return false;
}*/

int main(int argc, char **argv) {
	if (argc == 1) {
		print_how_to_use();
		return 0;
	} else if(argc == 4) {
		int w = atof(argv[1]);
		int h = atof(argv[2]);
		string filename = argv[3];
		image<rgb_pixel> result(w, h);
		for (uint_32 y = 0; y < result.get_height(); ++y) {
			for (uint_32 x = 0; x < result.get_width(); ++x) {
				result[x][y] = rgb_pixel(255, 255, 255);
			}
		}
		complex_number center(w/2, h/2); //Punkt ist in der Mitte
		double i = 0.00;
		double phi = 0;
		double r = 0;
		while(center.realteil() >= 0 && center.realteil() < w && center.imagteil() >= 0 && center.imagteil() < h) { //prüft, ob Pixel in gültigem Bereich
			result[center.realteil()][center.imagteil()] = rgb_pixel(0, 0, 0);
			phi +=  0.2;
			r += 0.05;
			//complex_number c(r * cos(phi), r * sin(phi));
			center += complex_number(r * cos(phi), r * sin(phi));
			cout << center << endl;
			//center += c;
			i += 0.0001;
		}		

		result.write(filename);
	}
	return 0;	
}

