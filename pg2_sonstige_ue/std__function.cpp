#include <iostream>
#include <functional>
#include <cassert>
#include <vector>

using std::cout, std::endl;

int add(int a, int b) { return a + b; }

int calculate(std::function<int(int, int)> func, int zahl1, int zahl2) {
	return func(zahl1, zahl2);
}

int main() {
	std::function<int(int ,int)> add_func = add;
	std::function<int(int, int)> mul_func = [](int zahl1, int zahl2) {
													return zahl1 * zahl2;
												};

	std::function<float(int, int)>div_func = [](int zahl1, int zahl2) {
												assert(zahl2 != 0 && " Zahl2 muss != 0 sein");
												return (float)zahl1 / (float)zahl2;
											 };
	std::function<int(int, int)>sub_func = [](int zahl1, int zahl2) {
											return zahl1 - zahl2;
										  };

	std::vector<std::function<int(int, int)>> my_fun_vector;
	my_fun_vector.push_back(add_func);
	my_fun_vector.push_back(mul_func);
	my_fun_vector.push_back(div_func);
	my_fun_vector.push_back(add_func);

	for (auto &my_fun : my_fun_vector)
		cout << my_fun(3, 4) << endl;

	return 0;
}
