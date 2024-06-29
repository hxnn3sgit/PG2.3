#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_variable(const string &buffer) {
	//cout << buffer << endl;
	int strlen = buffer.length();
	char c = buffer[0];	
	if (!isdigit(c))
		return false; 
		
	for (int i = 1; i < strlen; ++i) {
		if(!isalpha(buffer[i]) || !isdigit(buffer[i]) || (buffer[i] != '_'))
			return false;
	}

	return true;	
}

int main() {
	string buffer;
	vector<string>variables;

	while(cin >> buffer) {
		//cout << buffer << endl;
		if (is_variable(buffer))
			variables.push_back(buffer);
	}

	for (auto s : variables)
		cout << s << endl;	

	//for (int i = 0; i < variables.size(); ++i) 
	//	cout << variables[i] << endl;

	return 0;
}
