#include <iostream>

using namespace std;

template<typename T>
class dyn_arr {
private:
	T *data;
	unsigned int size;
public:
	dyn_arr() { cout << __PRETTY_FUNCTION__ << endl; }
	dyn_arr(int size) : size(size), data(new T[size]) {
		cout << __PRETTY_FUNCTION__ << endl;
	}
	~dyn_arr() {
		cout << __PRETTY_FUNCTION__ << endl;
		delete [] data;
	}
	template<typename U>
	friend ostream& operator<<(ostream &out, const dyn_arr<U> &my_arr);
};

template<typename T>
ostream dyn_arr::operator<<(ostream &out, const dyn_arr<T> &my_arr) {
	
	out << "[ ";
	for (const auto item : my_arr)
		out << item << " ";
	out << " ]";
	return out;
}

int main() {

	dyn_arr<int> my_ints(4);
	//cout << my_ints << endl;

	return 0;
}
