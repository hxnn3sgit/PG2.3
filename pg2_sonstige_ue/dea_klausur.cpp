#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

struct state {
	string name;
	bool finish = false;
	std::map<string, string> 
};

int main() {
	ifstream in;
	in.open("my_dea.dea");
	string line;
	string alphabet;
	int counter = 0;
	std::vector<string> things;
	while (getline(in, line, ' ' )) {
		if (counter == 0)
			alphabet += line;
		if (counter == 1)

		things.push_back(line);
	}

	//cout << ss.str() << endl;
	for (const auto &x : things)
		cout << x << endl;

	return 0;
}
