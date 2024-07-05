#include <iostream>
#include <initializer_list>

using namespace std;

/*template<typename T>
class my_init_list {
private:
	T *data;
	unsigned int size;
public:
	my_init_list(const T *data, unsigned int size) : data(data), size(size) {}
	unsigned int size() { return size; }

};*/

template<typename T>
class dynamicArray{
private:
	T *value;
	unsigned int size;
public:
	dynamicArray() : size(0), value(nullptr) {}
  	dynamicArray(int size) : size(size), value(new T[size]) {}
   	dynamicArray(initializer_list<T> init_list) {
		size = init_list.size();
		value = new T[size];
		int index = 0;
		for (T init_value : init_list)
			value[index++] = init_value;
	}	
	~dynamicArray();
	T& at(int i) const;
	void push(const T &x);
	T& operator=(const T &my_arr);
	bool operator==(const dynamicArray<T> &arr) const;
	T& operator[](int index);
	
	template<typename U>
	friend ostream& operator<<(ostream &out, const dynamicArray<U> &arr);
};

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

template<typename T>
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
		out << "[" << arr.at(i) << "] ";
	}
	return out;
}


int main(int argc, char **argv) {
	dynamicArray<int> my_array;

	if (argc > 1) {	
	for (int i = 1; i < argc; ++i)
   		my_array.push(atoi(argv[i]));

	cout << my_array << endl;

	}

	dynamicArray<string> my_strings;

	my_strings.push("Dere");
	my_strings.push("hallo");
	my_strings.push("tschau");

	cout << my_strings << endl;
	
	dynamicArray<int> my_ints_2;

	my_ints_2 = my_array;

	cout << my_ints_2 << endl;

	//cout << (my_ints_2 == my_array) << endl;

	dynamicArray<int> my_ints_3 = { 1, 2, 3, 4, 5 };
	cout << "my_ints_3: " << my_ints_3 << endl;

	dynamicArray<string> my_strings_2 = { "hallo", "ist", "ein", "test" };
	cout << my_strings_2 << endl;

	return 0;
}
