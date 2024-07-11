#include <iostream>
#include <functional>
#include <cstdlib>
#include <algorithm>

using std::endl, std::cout, std::string, std::vector;

int my_apply(std::function<int(int)> func, int zahl) {
	return func(zahl);
}

bool check_if_even_or_odd(std::function<bool(int)> func, int zahl) {
	return func(zahl);
}

int main() {
	float sum;
	auto add = [&sum](float a, float b) { sum = a + b ;return a + b; };
	auto doubled = [](float zahl) { return 2*zahl; };
	auto quadriert = [](float zahl) { return zahl*zahl; };
	auto is_even = [](int zahl) { return zahl%2==0; };

	/*for (int i = 0; i < 20; ++i) {
		if (my_apply(is_even, i))
			cout << i << " ist gerade\n";
		else
			cout << i << " ist ungerade\n";
	}*/

	std::vector<int> random_ints;
	int N = 50;

	for (int i = 0; i < 20; ++i)
		random_ints.push_back(rand()%N);

	std::funtion<int,(int,int)>  sorting = [](int zahl1, int zahl2) {
		return zahl1 < zahl2;
	};
	
	//std::sort(random_ints.begin(), random_ints.end(), [] (int zahl1, int zahl2) { return zahl1 < zahl2; } );

	std::sort(random_ints.begin(), random_ints.end(), sorting);

	for (auto &elem : random_ints)
		cout << elem << endl;

	return 0;
}
