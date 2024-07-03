#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <exception>

//using std::cout, std::endl, std::string, std::ostream, std::vector;
using namespace std;


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
	//associative_array()  
	~associative_array() { data.clear(); }
	//string get_key() { return data
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
	//cout << __PRETTY_FUNCTION__ << endl;
	//den vector durchgehen und diese mtrnr returnen die mit dem key other übereinstimmt
	for (const auto &item : data) {
		if (item.key == key) {
			return item.value;
		}
	}
	return -1; //jetzt dann: throw exception
}

int& associative_array::operator[] (const string &key) {
	//cout << __PRETTY_FUNCTION__ << endl;
	//todo:
	//speicheradresse vom zugehörigen value vom key hinzufügen
	for (auto &item : data) {
		if (key == item.key) { return item.value; }
	}
	throw std::invalid_argument("value nicht geaddet, key in dictionary nicht gefunden");
	//throw exception
	//data.push_back(my_pair(0, key));
	//return data.back().value;
}

int main() {
	associative_array mat_nr;
	//std::pair<string, int> my_pair(3370207, "Hannes Seidl");
	try {
	mat_nr["Hannes Seidl"] = 33070207;
	mat_nr["Neuer Student"] = 12345;
	mat_nr["Max Weber"] = 8842893;
	} catch(const std::exception &e) {
		cout << e.what() << endl;
	}
	cout << "matr_nr von 'Hannes Seidl' ist\n " << mat_nr["Hannes Seidl"] << endl;
	cout << "mat_nr von 'Neuer Student' ist\n " << mat_nr["Neuer Student"] << endl;
	cout << "mat_nr von 'Weber Max' ist\n " << mat_nr["Max Weber"] << endl; 
	return 0;
}
