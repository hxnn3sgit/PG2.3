#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <filestystem>

using namespace std;

struct DBEntry {
	DBEntry(const string &line) {
		
	}
	
	DBEntry(const string &line) {
		
	}

	vector<string> tags;
	string value;
};

vector<DBEntry> read_db(const filesystem::path &path) {
	vector<DatabaseEntry> database_entries;
	ifstream in(path);
	string line;
	while(getline(in, line)) {
		
	}	
	
}


int main(int argc, char **argv) {


	return 0;
}
