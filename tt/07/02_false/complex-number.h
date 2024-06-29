#include <iostream> 

using namespace std;

class complex_number {
 private:
	 double real;
	 double imag;
 public:
	 //complex_number(); //grade nicht benötigt
	 complex_number(double r);
	 complex_number(double r, double i);
	 ~complex_number();
	 double realteil();
	 double imagteil();
	 friend complex_number operator+(const complex_number &a, const complex_number &b);
	 friend complex_number operator+(const complex_number &other);
	 friend complex_number operator+(const int add, complex_number &other);
	 //friend complex_number &operator-(complex_number &complex_n);
	 //friend complex_number &operator*(complex_number &complex_n);
	 void operator+=(complex_number &complex_n);
	 //complex_number operator-=(complex_number &complex_n);
	 //complex_number operator*=(complex_number &complex_n);
	 friend ostream& operator<<(ostream &out, const complex_number &complex_n);
};

//complex_number &operator+(complex_number &complex_n);
/*complex_number &operator-(complex_number &complex_n);
complex_number &operator*(complex_number &complex_n);*/
