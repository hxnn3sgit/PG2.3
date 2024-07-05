#include <iostream>
#include <string>
#include <cctype>

using std::cout, std::endl, std::string;

class my_string : public std::string {
private:
	//char *data;
public:
	my_string() : std::string("") {}
	my_string(char zeichen, int anzahl);
	my_string(const std::string &to_c_string);
	//der andere c'tor no ka wie
	my_string toUpper();
	my_string toLower();
	my_string center(int w, char fill=' ');

	friend std::ostream &operator<<(std::ostream &out, const my_string &other);
};

my_string::my_string(char zeichen, int anzahl) {
	cout << __PRETTY_FUNCTION__ << endl;
	/*data = new char[anzahl];
	for (int i = 0; i < anzahl; ++i)
		data[i] = zeichen;
	data[anzahl] = '\0';*/

	std::string new_string;
	for (int i = 0; i < anzahl; ++i)
		new_string[i] = zeichen;
}

std::ostream &operator<<(std::ostream &out, const my_string &other) {
	out << "'";
	for (int i = 0; i < other.length(); ++i)
		out << other[i];
	out << "'";
	return out;
}

my_string::my_string toUpper() {
	return toupper(*this);
}

my_string::my_string toLower() {
	return tolower(*this);
}
 
int main() {
	my_string first_string('a', 5);
	cout << first_string << endl;	

	return 0;
}
