#include "calc.h"
#include "token.h"
#include <vector>

using namespace std;

bool syntax_check(const vector<token> &tokens) {
	int t_len = tokens.size();
	
	if ( (tokens[0].wich_kind() == token::kind::NUM) && (tokens[t_len-1].wich_kind() == token::kind::NUM) ) {
		for (int i = 1; i < (t_len-1); ++i) {
			if (i % 2 != 0) { //ungerade, muss NUM sein
				if (tokens[i].wich_kind() == token::kind::NUM) //muss OP sein
					return false;
			}
			else if (i % 2 == 0) { //gerade, muss OP sein
				if (tokens[i].wich_kind() == token::kind::OP) //muss NUM sein
					return false;
			}
		}
		return true;
	}
	return false;
}

double simple_eval_ltr(const vector<token> &tokens) {
	double res = tokens[0].get_number();
	
	for (int i =1; i < tokens.size(); i+=2) {
		char op = tokens[i].get_operator();
		int r_number = tokens[i+1].get_number();

		res = calc_value(res, op, r_number);
	}

	return res;
}

double calc_value(int left_number, char op, int right_number) {
	if (op == '+')
		return left_number + right_number;
	else if (op == '-')
		return left_number - right_number;
	else if (op == '*')
		return left_number * right_number;
	else if (op == '/') {
		assert(left_number != 0 && right_number != 0 && "cannot divide by zero\n");
		return left_number / right_number;
	} else {
		cout << "not a valid operator. Stopping program\n";
		exit(-1);
	}
}
