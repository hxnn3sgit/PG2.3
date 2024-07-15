#include <iostream>
#include <string>
#include <cmath>

using std::cout, std::endl;

class vector2d {
private:
	int x, y;
public:
	vector2d() : x(0), y(0) {}
	vector2d(int x, int y) : x(x), y(y) {}
	vector2d(const vector2d &other); //c ctor
	vector2d(vector2d &&other) noexcept; //move ctor
	double magnitude();
	vector2d &operator=(vector2d &&other) noexcept;
	void operator+=(const vector2d &other);
	bool operator==(const vector2d &other);
	friend std::ostream &operator<<(std::ostream &out, const vector2d &other);
	friend vector2d operator+(const vector2d &lhs, const vector2d &rhs);
	friend vector2d operator-(const vector2d &lhs, const vector2d &rhs);
	friend vector2d operator*(const vector2d &lhs, int scalar);
	friend vector2d operator*(int scalar, const vector2d &rhs) { return rhs * scalar; }
};

vector2d operator*(const vector2d &lhs, int scalar) {
	return vector2d(lhs.x * scalar, lhs.y * scalar);
}

vector2d::vector2d(const vector2d &other) {
	cout << __PRETTY_FUNCTION__ << endl;
	x = other.x;
	y = other.y;	
}

vector2d::vector2d(vector2d &&other) noexcept {
	x = other.x;
	y = other.y;
	other.x = 0;
	other.y = 0;
}

vector2d &vector2d::operator=(vector2d &&other) noexcept {
	if (this != &other) {
		x = other.x;
		y = other.y;
		other.x = 0;
		other.y = 0;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const vector2d &other) {
	return out << "(" << other.x << ", " << other.y << ")";
}

double vector2d::magnitude() {
	return sqrt( (pow(x, 2) + pow(y, 2)) );
}

bool vector2d::operator==(const vector2d &other) {
	if (x == other.x && y == other.y)
		return true;
	else
		return false;
}

void vector2d::operator+=(const vector2d &other) {
	x += other.x;
	y += other.y;	
}

vector2d operator+(const vector2d &lhs, const vector2d &rhs) {
	int new_x, new_y;
	new_x = lhs.x + rhs.x;
	new_y = lhs.y + rhs.y;
	return vector2d(new_x, new_y);
}

int main() {

	vector2d first_vec(2, 3);
	vector2d second_vec(1, 2);

	cout << first_vec << " hat Länge: " << first_vec.magnitude() << endl;
	
	first_vec += second_vec;

	cout << first_vec << " hat nach addieren Länge: " << first_vec.magnitude() << endl;
	
	vector2d third_vec = first_vec + second_vec;

	cout << "third vec: " << third_vec << endl;	


	vector2d my_vec(first_vec);
	cout << my_vec << endl;

	cout << "----------------------------------------\n";	

	vector2d first_move_vec(1, 2);
	vector2d second_move_vec;

	cout << "before move: first: " << first_move_vec << ", second: " << second_move_vec << endl;

	second_move_vec = std::move(first_move_vec);

	cout << "after move: first: " << first_move_vec << ", second: " << second_move_vec << endl;
	
	cout << "copying...: " << vector2d(my_vec) << endl;

	vector2d test_vec(2,3);

	cout << test_vec * 3 << endl;
	cout << 3 * test_vec << endl;

	return 0;
}
