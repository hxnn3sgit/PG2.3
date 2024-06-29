#include <iostream> 
#include <cmath>

using namespace std;

class complex_number {
private:
	double real, imag;
public:
	//Konstruktoren
	complex_number(double r) : real(r), imag(0) {}
	complex_number(double r, double i) : real(r), imag(i) {}
	//Destruktor wird nicht benötigt
	
	double realteil();
	double imagteil();

	friend ostream& operator<<(ostream &out, const complex_number &other);

	complex_number operator+=(const complex_number &other);
	complex_number operator-=(const complex_number &other);
	complex_number operator*=(const complex_number &other);

	double abs() { return (sqrt(real*real+imag*imag)); }

	friend complex_number operator+(const complex_number &c1, const complex_number &c2);
	friend complex_number operator-(const complex_number &c1, const complex_number &c2);
	friend complex_number operator*(const complex_number &c1, const complex_number &c2);
};

void print_how_to_use();
