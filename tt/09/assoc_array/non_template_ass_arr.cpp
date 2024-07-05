#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>

//using std::cout, std::endl, std::string, std::ostream, std::vector;
using namespace std;

/*template<typename T>
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
}*/

struct my_pair {
	int value;
	string key;
	my_pair(int value, const string &key) : value(value), key(key) {}
};

class associative_array {
public:
	//dynamicArray<my_pair> data;
	vector<my_pair> data;
public:
	associative_array() {}
	associative_array(int matr_nr, string name);
	~associative_array() { data.clear(); }
   	void push(int value, const string &key);
	int operator[](const string &key) const;
	int& operator[] (const string &key);
	friend ostream& operator<<(ostream &out, const associative_array &other);   
};



void associative_array::push(int value, const string &key) {
	data.push_back(my_pair(value, key));
}

associative_array::associative_array(int matr_nr, string name) {
	data.push_back(my_pair(matr_nr, name));
}

int associative_array::operator[] (const string &key) const {
	cout << "subscript const" << endl;
	//den vector durchgehen und diese mtrnr returnen die mit dem key other übereinstimmt
	for (const auto &item : data) {
		if (item.key == key) {
			return item.value;
		}
	}
	return -1; //jetzt dann: throw exception
}

int& associative_array::operator[] (const string &key) {
	cout << "subscript non const" << endl;
	//todo:
	//speicheradresse vom zugehörigen value vom key hinzufügen
	for (auto &item : data) {
		if (key == item.key) { return item.value; }
	}
	data.push_back(my_pair(0, key));
	return data.back().value;
}

int main() {
	associative_array mat_nr;
	cout << "studs werden hinzugefügt" << endl;
	mat_nr["Hannes Seidl"] = 33070207;
	mat_nr["Neuer Student"] = 12345;
	mat_nr["Max Weber"] = 8842893;

	const associative_array& const_ref_mat_nr = mat_nr;

	cout << "matr_nr von 'Hannes Seidl' ist\n " << const_ref_mat_nr["Hannes Seidl"] << endl;
	cout << "studs sind hinzugefügt worden" << endl;
	cout << "mat_nr von 'Neuer Student' ist\n " << const_ref_mat_nr["Neuer Student"] << endl;
	cout << "mat_nr von 'Weber Max' ist\n " << const_ref_mat_nr["Max Weber"] << endl; 
	
	std::cin.get();
	
	return 0;
}
