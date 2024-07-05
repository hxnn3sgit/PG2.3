#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>

using namespace std;

template<typename T, V>
struct my_pair {
	T value;
	V key;
	my_pair(cpnst T &value, const V &key) : value(value), key(key) {}
};

template<typename T, V>
class associative_array {
	public:
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
	//den vector durchgehen und diese mtrnr returnen die mit dem key other übereinstimmt
	for (const auto &item : data) {
		if (item.key == key) {
			return item.value;
		}
	}
	return -1; //jetzt dann: throw exception
}

int& associative_array::operator[] (const string &key) {
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
	
	return 0;
}
