#include <iostream>
#include <png.h>

using namespace std;

int main() {

	png::image< png::index_pixel > image;
	png::palette pal(256);
	for (size_t i = 0; i < pal.size(); ++i)
		pal[i] = png::color(i, 255 - i, i);	
	
	image.set_palette(pal);
	image.write("palette.png");

	return 0;
}
