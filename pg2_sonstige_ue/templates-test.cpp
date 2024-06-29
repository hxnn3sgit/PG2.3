#include <iostream>
#include <string>

using namespace std;

template<int N>
class arrayy {
private:
	int my_array[N];
public:
	//arrayy(int size) : {}
	int get_size() const { return N; }
};

int main() {

	arrayy<5> my_arr;
	cout << my_arr.get_size() << endl;
	return 0;
}
