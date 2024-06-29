#include "complex-number.h"
#include <iostream>
#include <cmath>

using namespace std;
//Konstruktoren:
complex_number::complex_number(double r) : real(r), imag(0) {}
complex_number::complex_number(double r, double i) : real(r), imag(i) {}

complex_number::~complex_number() {
	//delete stuff, aber nix mit new allokiert
}

//getter:
double complex_number::realteil() {
	return real;
}

double complex_number::imagteil() {
	return imag;
}

//Operatorüberladungen:
void complex_number::operator+=(complex_number &complex_n) {
	real += complex_n.real;
	imag += complex_n.imag;
}
/*void complex_number::operator-=(complex_number &complex_n) {
		
}
void complex_number::operator*=(complex_number &complex_n) {}*/

ostream& operator<<(ostream &out, const complex_number &complex_n) {
	out << complex_n.real << "+" << complex_n.imag << "i";
	return out;
	//alles in eins schreiben und dann returnen?
}
//wos mochd des const nomol schnall? des hinter da parameterliste
//geht:
complex_number operaor+(const complex_number &a, const complex_number &b) {
	cout << __PRETTY_FUNCTION__ << endl;
	return complex_number(a.real + b.real, a.imag + b.imag);
}
//geht ned:
/*complex_number operator+(const complex_number &other) {
	cout << __PRETTY_FUNCTION__ << endl;
	return (complex_number(real + other.real, imag + other.imag));
}*/

complex_number operator+(int add, complex_number &other) {
	cout << __PRETTY_FUNCTION__ << endl;
	return complex_number(other.real + add, other.imag + add);
}

/*complex_number operator+(complex_number &lhs, const int add) {
	return complex_number(lhs.real + add, lhs.imag + add);
}*/
//complex_number &operator-(complex_number &complex_n) {}
//complex_number &operator*(complex_number &complex_n) {}
