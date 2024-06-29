#include "k19_5.h"
#include <iostream>

Point3D Point3D::operator-() {
	return Point3D(-x, -y, -z);
}

std::ostream &operator<<(std::ostream &out, const Point3D &other) {
	return out << "(" << other.x << ", " << other.y << ", " << other.z << ")";
}
