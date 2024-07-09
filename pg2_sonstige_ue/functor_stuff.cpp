#include <iostream>
#include <vector>

using std::cout, std::endl;

template<typename T>
struct add_two_numbers {
	T operator() (T value1, T value2) { return value1 + value2; }
};

struct adder_with_constant {
	int constant;
	adder_with_constant(int constant) : constant(constant) {}
	void operator() (std::vector<int> &my_vec) {
		for (auto &elem : my_vec)
			elem = elem + constant;
	}
};

int main() {

	add_two_numbers<int> my_functor;
	cout << my_functor(2, 3) << endl;	

	std::vector<int> my_numbers;

	int N = 50;

	for (int i = 0; i < 20; ++i)
		my_numbers.push_back(rand()%N);

	adder_with_constant my_adder_with_constant(4);

	my_adder_with_constant(my_numbers);

	cout << "my_numbers before functor:" << endl;
	for (auto &elem : my_numbers)
		cout << elem << endl;
	
	my_adder_with_constant(my_numbers);

	cout << "my_numbers after functor:" << endl;
	for (auto &elem : my_numbers)
		cout << elem << endl;


	return 0;
}
