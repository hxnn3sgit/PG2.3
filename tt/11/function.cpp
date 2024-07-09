#include <iostream>
#include <cmath>

using namespace std;

double f(double x) { 
	cout << "f(x) outside" << endl;
	return sin(x);
}

void so_important_stuff(const double &dbl) {
	cout << "so_important_stuff " << dbl << endl;
}	

int main(int argc, char ** argv) {
	double n = 10000.0;
	double sum = 0.0;

	auto calc_values = [&sum](double i) { 
		cout << "local test" << endl;
		int temp = sin(i/100);
		sum += temp;
		return sum; 
	};

	for (int i = 0; i < n; ++i)
		so_important_stuff(calc_values(i/100));
	
	cout << sum << endl;

	cout << argv[3];

}
