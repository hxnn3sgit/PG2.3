#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using std::cout, std::endl, std::string, std::ostream, std::vector;

struct my_pair {
	int value;
	string key;
	my_pair(int value, const string &key) : value(value), key(key) {}
};

class associative_array {
private:
	//dynamicArray<my_pair> data;
	vector<my_pair> data;
public:
	associative_array() {}
	associative_array(int matr_nr, string name);
	//associative_array()  
	~associative_array() { data.clear(); }
   	void push(int value, const string &key);
	int operator[](const string &key) const;
	associative_array& operator[] (const string &key);
	friend ostream& operator<<(ostream &out, const associative_array &other);   
};


associative_array::associative_array(int matr_nr, string name) {
	data.push_back(my_pair(matr_nr, name));
}

int associative_array::operator[] (const string &key) const {
	//den vector durchgehen und diese mtrnr returnen die mit dem key other übereinstimmt
	for (auto item : data) {
		if (item.key == key) {
			return item.value;
		}
	}
	return -1; //jetzt dann: throw exception
}

associative_array&::operator[] (const s

int main() {
	associative_array mat_nr;
	//mat_nr["Hannes Seidl"] = 3370207;
	//cout << "matr_nr von stud ist " << mat_nr["Hannes Seidl"] << endl;

	return 0;
}
