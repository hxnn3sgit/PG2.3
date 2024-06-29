#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cout, std::endl, std::string, std::ostream, std::vector;

template<typename T>
class dynamicArray{
private:
	T *value;
	unsigned int size;
public:
	dynamicArray() : size(0), value(nullptr) {}
  	dynamicArray(int size) : size(size), value(new T[size]) {}  	
	~dynamicArray();
	T& at(int i) const;
	void push(const T &x);
	T& operator=(const T &my_arr);
	bool operator==(const dynamicArray<T> &arr) const;
	T& operator[](int index);
	
	template<typename U>
	friend ostream& operator<<(ostream &out, const dynamicArray<U> &arr);
};

struct my_pair {
	int value;
	string key;
	my_pair(int value, const string &key) : value(value), key(key) {}
};

class associative_array {
private:
	//dynamicArray<my_pair> data;
	dynamicArray<my_pair> data;
public:
	associative_array(int matr_nr, string name) : data(my_pair(matr_nr, name)) {}
	//associative_array()  
	~associative_array();
   	void push(int value, const string &key);
	int& operator[](const string &my_str);
	friend ostream& operator<<(ostream &out, const associative_array &other);   
};

/*void associative_array::push(int value, const string &key) {
	int *new_data = new int[size+1];

	for (
}*/


int main() {
	//associative_array matr_nr(3370207, "Hannes Seidl");
	my_pair test(3370272, "Hannes Seidl");

	return 0;
}

template<typename T>
dynamicArray<T>::~dynamicArray() {
	delete [] value;
	size = 0;
}

template<typename T>
void dynamicArray<T>::push(const T &x) {
		T *new_values = new T[size+1];
		for (int i = 0; i < size; ++i)
			new_values[i] = value[i];
		new_values[size] = x;
		size += 1;
		delete [] value;
		value = new_values;
	
}

template<typename T> //geht noch nicht
bool dynamicArray<T>::operator==(const dynamicArray<T> &arr) const {
	if (arr.size == size) {
		for (int i = 0; i < size; ++i) {
			if (value[i] != arr[i])
				return false;
		}
		return true;		
	}
	return false;	
}

template<typename T>
T& dynamicArray<T>::operator=(const T &my_arr) {
	for (int i = 0; i < size; ++i)
		my_arr[i] = value[i];
}

template<typename T>
T& dynamicArray<T>::at(int i) const {
	return this->value[i];
}

template<typename T>
T& dynamicArray<T>::operator[](int index) {
	return value[index];
}

template<typename T>
ostream& operator<<(ostream &out, const dynamicArray<T> &arr) {
	for (unsigned int i = 0; i < arr.size; ++i) {
		out << "[" << arr.at(i) << "]\t";
	}
	return out;
}
