#include <iostream>
#include <vector>

int strlen(const char *chars);

using namespace std;

class my_string {
private:
	char *data;
	int len;
public:
	my_string(const char *string_data) : data(new char[strlen(string_data)+1]), len(strlen(string_data)) {
		for (int i = 0; i < len; ++i)
			data[i] = string_data[i];
		data[len+1] = '\0';
	}
	my_string(const my_string &other) {
		my_string new_str = new my_string[other.len+1];
		for (int i = 0; i < other.len; ++i)
			new_str[i] = other[i];

		new_str[len] = '\0';
	}
	~my_string() { delete [] data; len = 0; }

	int length() { return len; }
	char operator[](int index) const;
	friend ostream& operator<<(ostream &out, const my_string &other);
};

ostream& operator<<(ostream &out, const my_string &other) {
	out << "'";
	for (int i = 0; i < other.len; ++i)
		out << other.data[i];
	out << "'";
	return out;
} 

char my_string::operator[](int index) const {
	if (index < 0 || index >= len) //>=
		throw out_of_range("Index out of range"); 
	return data[index]; 
}

int main() {
	my_string name("Hannes");
	cout << name << endl;
	
	cout << name[1] << endl;

	//name[1] = 't';

	return 0;
}

int strlen(const char *chars) {
	cout << __PRETTY_FUNCTION__ << endl;
	int counter = 0;
	while (chars[counter] != '\0') { counter++; }
	
	cout << counter << endl;
	return counter;
}
