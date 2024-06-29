#include <iostream>
#include <string>
#include <sstream>

using namespace std;

static int counter = 0;

class Ding {
	string name;
public:
	Ding() {}
	Ding(const Ding &anderes_ding) {
		cout << __PRETTY_FUNCTION__ << "c'ctor" << endl;
		name = anderes_ding.name;
	}
	Ding(const char *name) {
		cout << __PRETTY_FUNCTION__ << "ctor" << endl;
	}
	explicit Ding(int i) {}
	~Ding() { cout << __PRETTY_FUNCTION__ << endl; }
	friend ostream& operator<<(ostream &out, const Ding &d) {
		return out << "'" << d.name << "'" << endl;
	}
};

void f(const std::string &x) {}
void f(const Ding &d) {}

void g(const Ding &d) {}

Ding h(Ding d, int n) { if (n > 0) return h(d, n-1); return d; }

#define ____ cout << "\nZeile " << __LINE__ << "-----------------------\n" << endl;

int main() {
	std::string hello = "Hello";

	f(Ding("hello"));
	g("hello");
	____

	//Ding d101 = 100; '=' not overloaded
	Ding d100(100);
	g(Ding(101));
	Ding copy_ding(d100);
	Ding copy_ding2 = d100;
	____

	auto d = h("hello", 3);
	cout << "Kam zurück: " << d << endl;
	____

	return 0;
}
