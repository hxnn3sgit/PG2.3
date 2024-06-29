#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int stringlength(const string &my_string) { return my_string.length(); }
//int intvalue() { return value; } //sinn?

template<typename T>
int laenge(const T &my_variable) { return string(my_variable).length(); }

template<typename T, typename F>
int largest(const vector<T> &my_vec, F function) {
	int index = 0;

	for (int i = 0; i < my_vec.size(); ++i) {
		if (index < function(my_vec[i]))
			index = i;
	}

	return index;
}

int main() {
	vector<string> strings = {"Schreiben", "Sie", "eine", "Template-Funktion", "die"};
	cout << "index: " << largest(strings, laenge) << endl;
	cout << "value: " << strings[largest(strings, laenge)] << endl;

	//vector<int> ints = {1, 4, 2, 7, 2, 7, 2, 9, 4, 2, 6};
	//cout << "index: " << largest(ints, laenge) << endl;
	//cout << "value: " << ints[largest(ints, laenge)] << endl;


	return 0;
}
