#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*template<typename T>
ostream& vector::operator<<(ostream &out, const T &other) {
	out << "[";
	for (auto const &item : other)
		out << item << " ";
	out << "]";
	return out;
}*/

template<typename T, typename U>
void my_swap(T &a, U &b) {
	//cout << "before swap, a: " << a << ", b: " << b << endl;
	T help = a;
	a = b;
	b = help;
	//cout << "after swap, a: " << a << ", b: " << b << endl;
}

struct X {
public:
	int x1, x2;
	X() {}
	X(int x1, int x2) : x1(x1), x2(x2) {}
	friend ostream& operator<<(ostream &out, const X &my_x) {
		return out << "x1: " << my_x.x1 << ", x2: " << my_x.x2;
	}
};

int main() {
	int a = 0, b = 1;
	my_swap(a, b);
	
	string aa = "string aa", bb = "string bb";
	//my_swap(aa, bb);
	
	X x1(1, 1);
	X x2(2, 2);
	my_swap(x1, x2);

	vector<X> my_X1{x1};	
	vector<X> my_X2{x2};
	my_swap(my_X1, my_X2);

	//vector<float> v1{1, 1}, v2{2, 2};
	vector<float> v1, v2;
	my_swap(v1, v2);

	return 0;
}
