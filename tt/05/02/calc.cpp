#include "calc.h"

using namespace std;
namespace math {
float calc(const char op, const int left, const int right) {
	switch(op) {
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*': 
			return left * right;
		case '/':
			assert(right != 0 && "Nenner ist 0");
			return left / (float)right;
		default:
			std::cout << "left: " << left << " right: " << right << " op: " << op << std::endl;
			std::cerr << "Ungueltiges Rechenzeichen uebergeben. Programm beenden...\n";
			exit(-1);
	}
}

bool valid_op(const char op) {
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return true;
	else
		return false;
}

float calc(const string &args) {
	stringstream ss;
	ss << args;
	int left, right;
	char op;

	ss >> left;
	ss >> op;
	ss >> right;

	return calc(op, left, right);
}

float calc() {
	stringstream ss;
	string line;
	getline(cin, line);
	ss << line;
	int left, right;
	char op;
	ss >> left;
	ss >> op;
	ss >> right;
	return calc(op, left, right);
}

}
