#include "complex-number.h"
#include <iostream>
#include <cmath>

//Konstruktoren in Header-File definiert
//complex_number::complex_number(int r) : real(r), imag(0) {}
//complex_number(int r, int i) : real(r), imag(i) {}
//Destruktor braucht man momentan nicht
//~complex_number() {}
//getter:
double complex_number::realteil() { return real; }
double complex_number::imagteil() { return imag; }	
//ostream Operator:
ostream &operator<<(ostream &out, const complex_number &other) {
	return out << other.real << "+" << other.imag << "i";
}
//+=, -=, *= Operatoren:
complex_number complex_number::operator+=(const complex_number &other) {
	real += other.real;
	imag += other.imag;
	return *this;
}
complex_number complex_number::operator-=(const complex_number &other) {
	real -= other.real;
	imag -= other.imag;
	return *this;
}
complex_number complex_number::operator*=(const complex_number &other) {
	double temp_real = real * other.real - imag * other.imag;
	imag = real * other.imag + imag * other.real;
	real = temp_real;
	return *this;
}
/*double complex_number::abs() {
	return (sqrt(real*real+imag*imag));
}*/

//friend complex_number operator+(const complex_number &c1, const complex_number &c2);
//friend complex_number operator-(const complex_number &c1, const complex_number &c2);
//friend complex_number operator*(const complex_number &c1, const complex_number &c2);


complex_number operator+(const complex_number &c1, const complex_number &c2) {
	return complex_number(c1.real + c2.real, c1.imag + c2.imag);
}

complex_number operator-(const complex_number &c1, const complex_number &c2) {
	return complex_number(c1.real - c2.real, c1.imag - c2.imag);
}

//stimmt so glaube no ned
complex_number operator*(const complex_number &c1, const complex_number &c2) {
	return complex_number(c1.real * c2.real, c1.imag * c2.imag);
}

void print_how_to_use() {
	cout << "first argument: width, second argument: height, third argument: filename\n";
}
