#include <iostream>
#include <fstream>
#include "associative_array.h"
#include <filesystem>

namespace fs = std::filesystem;

using namespace std;

struct number_data {
	int alter, vl, ue, note;
	number_data() : alter(0), vl(0), ue(0), note(0) {}
	number_data(int alter, int vl, int ue, int note) : alter(alter), vl(vl), ue(ue), note(note) {}
	friend ostream& operator<<(ostream &out, const number_data &other);
};

ostream &operator<<(ostream &out, const number_data &other) {
	return out << "Alter: " << other.alter << ", VL: " << other.vl << " UE: " << other.ue << ", Note: " << other.note;
}

void fill_array(associative_array<string, number_data> &student_data) {
	//store things from file students.txt
}

int main(int argc, char **argv) {
	ifstream file_out;

	number_data first_dataset(21, 13, 4, 2.7);
	associative_array<number_data, string> student_data;	
	student_data["Katlin Albrecht"] = first_dataset;

	cout << student_data << endl;
	//fill_array(student_data);
	
	fs::path p = "./students.txt";
	file_out.open(p);
	
	int counter = 0;
	if (file_out.is_open()) {
		string line;
		//while (getline(file_out, line)) {
			//cout << line << endl;

		//}
		getline(file_out, line);
	} else
		cerr << "File couldnt be openend\n";

	return 0;
}
