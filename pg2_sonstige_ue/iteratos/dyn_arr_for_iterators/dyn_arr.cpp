#include <iostream>

using std::cout, std::endl, std::ostream;

class dynamic_array_of_ints {
private:
	int *data;
	unsigned int size;
public:
	class iterator {
		private:
			int *data_element;
		public:
			iterator(int *ptr) : data_element(ptr) {}
			int& operator*() { return *data_element; }
			iterator& operator++() { ++data_element; return *this; }
			bool operator==(const iterator &other) { 
				return data_element == other.data_element; 
			}
			bool operator!=(const iterator &other) {
				return data_element != other.data_element;
			}	
	};
	dynamic_array_of_ints() : data(nullptr), size(0) {}
	dynamic_array_of_ints(unsigned int size) : data(new int[size]), size(size) {}
   	~dynamic_array_of_ints() { delete [] data; }
	int operator[](int index) const { return data[--index]; }
	void push(int value);
	iterator begin() { return data; }
	iterator end() { return data + size; }
	friend ostream &operator<<(ostream &out, const dynamic_array_of_ints &other);
};

void dynamic_array_of_ints::push(int value) {
	int *new_data = new int[size+1];

	for (int i = 0; i < size; ++i)
		new_data[i] = data[i];

	new_data[size] = value;
	size += 1;

	delete [] data;
	data = new_data;
}

ostream &operator<<(ostream &out, const dynamic_array_of_ints &other) {
	for (int i = 0; i < other.size; ++i)
		out << "[" << other.data[i] << "]\t";
	return out;
}

int main() {

	dynamic_array_of_ints my_array;
	 
	for (int i = 0; i < 20; ++i)
		my_array.push(rand()%50);

	cout << my_array << endl;
	
	cout << my_array[12] << endl;

	for (auto &x : my_array)
		cout << x << endl;
	return 0;
}
