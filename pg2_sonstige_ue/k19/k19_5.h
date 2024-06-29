#include <iostream> 

using namespace std;

class Point3D {
public:
	double x, y, z;
	Point3D(double x, double y, double z) : x(x), y(y), z(z) {}
	Point3D operator-();

	friend std::ostream &out(std::ostream &out, const Point3D &other);
};
