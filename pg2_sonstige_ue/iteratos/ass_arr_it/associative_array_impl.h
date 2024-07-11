#include "associative_array.h"
#include <vector>
#include <string>
#include <exception>


using namespace std;

template<typename V, typename K>
associative_array<V, K>::associative_array(const V &matr_nr, const K &name) {
	data.push_back(my_pair<V, K>(matr_nr, name));
}

template<typename V, typename K>
void associative_array<V, K>::push(const V &value, const K &key) {
	data.push_back(my_pair<V, K>(value, key));
}

template<typename T, typename U>
ostream& operator<<(ostream &out, const associative_array<T, U> &other) {
	for (const auto &pair : other.data) 
		out << pair.key << " [" << pair.value << "]" << endl;

	return out;
}

template<typename V, typename K>
V associative_array<V, K>::operator[] (const K &key) const {
	//cout << "subscript const" << endl;
	//den vector durchgehen und diese mtrnr returnen die mit dem key other übereinstimmt
	for (const auto &item : data) {
		if (item.key == key) {
			return item.value;
		}
	}
	throw out_of_range("key not found in associative array");
	//return -1; //jetzt dann: throw exception
}

template<typename V, typename K>
V& associative_array<V, K>::operator[] (const K &key) {
	//cout << "subscript non const" << endl;
	//todo:
	//speicheradresse vom zugehörigen value vom key hinzufügen
	for (auto &item : data) {
		if (key == item.key) { return item.value; }
	}
	V default_value;
	data.push_back(my_pair<V, K>(default_value, key));
	return data.back().value;
}
