#include <iostream>
#include <exception>

using std::cout, std::endl;

class neg_num_exception;

bool check_positive(int number) {
   	if (number < 0) {
		throw neg_num_exception();
	}
	else
		return true;
}

class neg_num_exception : public std::exception {
public:
	const char* what() noexcept override {
		return "no negative number allowed";
	}
};

int main(int argc, char **argv) {
	int number = 3;
	if (argc == 2)
		number = atoi(argv[1]);	
	
	try {
		check_positive(number);
		cout << number << " is positive!" << endl;
	} catch(neg_num_exception &e) {
		cout << e.what() << endl;
	}
	

	return 0;
}
