#include "dyn_arr_normal.h"
#include <iostream>

dyn_arr::~dyn_arr() {
}

int& dyn_arr::at(unsigned int index) {
	return data[index];
}

std::ostream& operator<<(std::ostream &out, const dyn_arr &my_arr) {
	out << "[";
	for (int i = 0; i < my_arr.size; ++i) {
		out << my_arr.data[i] << " ";
		std::cout << "operator<<: " << my_arr.data[i] << std::endl;
	}
	out << "]";
	return out;
}

void dyn_arr::push(int value) {
	int new_size = size + 1; //size of array gets bigger +1
	int *new_data = new int[new_size];

	for(int i = 0; i < size; ++i)
		new_data[i] = data[i];

	new_data[new_size-1] = value;

	data = new_data;
	size = new_size;
	delete [] data;
}
