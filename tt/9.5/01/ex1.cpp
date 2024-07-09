#include <iostream>
#include <fstream>
#include "associative_array.h"
#include <filesystem>
#include <algorithm>

namespace fs = std::filesystem;

using namespace std;

struct number_data;

/*template<typename T, typename V>
struct filter_predicate {
	bool operator() (const std::pair<T, V> &pair) const {
		
	}
};*/

bool is_right_name() {
	return true;
}

/*void course_overview(const associative_array<string, number_data> &student_data, const string &student_name) {
	
	//if (auto it = std::find_if(student_data.data.begin(), student_data.data.end(), is_right_name) {
	auto it = std::find_if(student_data.data.begin(), student_data.data.end(), is_right_name);	
	cout << it << endl;
	//} else
		//cout << "Person not found" << endl;
}*/

struct number_data {
	int alter, vl, ue;
   	float note;
	number_data() : alter(0), vl(0), ue(0), note(0) {}
	number_data(int alter, int vl, int ue, float note) : alter(alter), vl(vl), ue(ue), note(note) {}
	friend ostream& operator<<(ostream &out, const number_data &other);
};

ostream &operator<<(ostream &out, const number_data &other) {
	return out << "Alter: " << other.alter << ", VL: " << other.vl << " UE: " << other.ue << ", Note: " << other.note;
}

int main(int argc, char **argv) {
	ifstream file_out;

	associative_array<number_data, string> student_data;	
	fs::path p = "./students.txt";
	file_out.open(p);
	
	try {
		string line;
		string student_name;
		float counter = 1;
		int alter = 0;
		int vl = 0;
		int ue = 0;
		float note = 0;
		while (getline(file_out, line)) {
			if (counter == 1) {
				student_name = line;
				++counter;
			} else if (counter == 2) {
				alter = atoi(line.c_str());
				++counter;
			} else if (counter == 3) {
				vl = atoi(line.c_str());
				++counter;
			} else if (counter == 4) {
				ue = atoi(line.c_str());
				++counter;
			} else if (counter == 5) {
				note = atof(line.c_str());
				student_data[student_name] = number_data(alter, vl, ue, note);
				counter = 1;
			}
		}
	} std::throw {
		cerr << "File couldnt be openend\n";
	}
	
	cout << student_data << endl;


	return 0;
}
