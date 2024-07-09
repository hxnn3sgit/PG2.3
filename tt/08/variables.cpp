#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <regex>

using std::cout, std::cerr, std::endl, std::string, std::cin, std::vector, std::stringstream;

using namespace std;

int main() {
	vector<string> variables;
	string buffer;
	/*while (getline(cin, buffer, ' ')) {  	
		variables.push_back(buffer);
	}*/

	for (int i = 0; i < variables.size(); ++i)
		cout << variables[i] << endl;

	std::stringstream ss;

	for (int i = 0; i < variables.size(); ++i)
		ss << variables[i];

	cout << "stringstream:\t" << ss.str() << endl;
	string vars;
	char c;
	while (ss.get(c)) {
		if (c != '\t' && c != '\n' && c != '\r' && c != '"' && /*c != ''' &&*/ c != '\?')
			vars += c;
		}
	ss.str(string());
	ss << vars;

	cout << "stringstream:\t" << ss.str() << endl;

	alsdj

	return 0;
}
