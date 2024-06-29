#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;

enum TokenType {
	TYPE,
	IDENTIFYER,
	SYMBOL,
	UNKNOWN
};

struct Token {
	TokenType type;
	string value;
}

vector<Token> tokenize(const string &code) {

}

int main() {
	string code;
	getline(cin, code);
	vector<Token> tokens = tokenize(code);

	int start = 0;
	
}
