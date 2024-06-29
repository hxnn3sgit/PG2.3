#include <iostream>
#include "dyn_arr.h"

using namespace std;

void determine_primes(dynamic_array &array, int end) {
	for (int i = 3; i <= end; ++i) {
		bool is_prime = true;
		for (unsigned int j = 0; j < array.len(); ++j) {
			if (array.at(j) % i == 0) {
				is_prime = false;
				break;	
			}
		}
		if (is_prime)
			array.push(i);
	}
	cout << "prime(s) added\n";
}

int main(int argc, char **argv) {
	dynamic_array array;

	for (int i = 1; i < argc; ++i)
		array.push(atoi(argv[i]));

	array.print_array();
	return 0;
}
