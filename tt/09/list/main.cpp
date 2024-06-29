#include "list.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	list my_list;

	for (int i = 1; i < argc; ++i) {
		my_list.prepend(atoi(argv[i]));
	}

	cout << my_list << endl;

	return 0;
}
