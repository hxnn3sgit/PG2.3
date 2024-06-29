#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//mit std::reverse funktion
//oder: mit in place umkehren, aber ka
template<typename T>
void reverse_vector(vector<T> &my_vec) {
	vector<T> temp_vector;
	
	int my_vec_size = my_vec.size()-1;

	for (int i = my_vec_size; i >= 0; --i) {
		temp_vector.push_back(my_vec[i]);
	}
	
	my_vec.clear();

	for (int i = 0; i < temp_vector.size(); ++i)
		my_vec.push_back(temp_vector[i]);
}

int biggest_element(const vector<int> &my_int_vec) {
	int largest_element = INT_MIN;

	for(const auto &item : my_int_vec) {
		if (item > largest_element)
			largest_element = item;
	}

	return largest_element;
}
	
int main() {
	vector<int> my_vector{-232, -23, -25231, -13134};
	reverse_vector(my_vector);
	
	cout << "largest element in vector: " << biggest_element(my_vector) << endl;

	return 0;
}
