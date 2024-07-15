#include <vector>
#include <iostream>

using std::cout, std::endl;

template<typename T>
void reverse(std::vector<T> &vec) {
	cout << "before reverse: " << endl;
	for (const auto &x : vec)
		cout << "[" << x << "]";
	cout << endl;

	std::vector<T> help;

	for (int i = vec.size()-1; i >= 0; --i)
		help.push_back(vec[i]);

	vec.clear();

	for (int i = 0; i < vec.size(); ++i) {
		vec.push_back(help[i]);
	}

	cout << "after reverse: " << endl;
	for (auto x : vec)
		cout << "[" << x << "]";


}

int main() {

	std::vector<int> my_vec = {1,2,3,4,5,6,7};
		
	reverse(my_vec);


	return 0;
}
