#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

void print_help();
void append_content(const int argc, char **argv);
void query(const string &tags);

int main(int argc, char **argv) {
	if (argc == 2) {
		if (string(argv[1]) == "-h" || string(argv[1]) == "--help") {
			print_help();
		} else {
			cout << "Angegebene Operation nicht unterstuetzt. Programm beenden...\n";
			return(-1);
		}
	} else if (argc >= 4) {
		string mode(argv[1]);
		if (mode == "-a" || mode== "--append") 
			append_content(argc, argv);
	} else if (argc == 3) {
		string mode = argv[1];
		if (mode == "-q" || "--query") {
			string tags(argv[2]);
			query(tags);
		} else {
			cout << "Falsche Parameter zum Suchen uebergeben. Programm beenden\n";
			return(-1);
		}
	}

	else {
		cout << "Falsche oder keine parameter uebergeben. Programm beenden...\n";
		return(-1);
	}	
	
	return 0;
}

void print_help() {
	cout << "Mit -h oder --help wird dieses Menü aufgerufen\n";
	cout << "Mit '-a tag1,tag2,...,tagn content' wird Tag mit zugehörigem Content angehängt\n";
   cout << "Mit '-q tag1,tag2,...,tagn' wird gesamter Content auf alle Tags untersucht und ausgegeben\n";	
}
//int kopieren ist schneller als referenz auf pointer
void append_content(const int argc, char **argv) {
	string tags(argv[2]);
	ofstream out;
	//string content; //ostringstream verwenden
	/*for (int i = 3; i < argc; ++i) 
		content += (string)argv[i] + " ";
	content += "\n";*/

	out.open("tagdb.txt", ios::app);
	out << tags << " ";
	for (int i = 3; i < argc; ++i) {
		out << argv[i] << " ";
	}
	out << '\n';	
	//out.close(); //braucht man nicht, weil destruktor eingreift
}

void query(const string &tags) {
	vector<string> tags_v;
	stringstream ss(tags);

	string tag;

	while (getline(ss, tag, ',')) {
		tags_v.push_back(tag);
	}

	//datei öffnen, mit jedem tag bis zum leerzeichen durchgehen und vergleichen, falls tag enthalten-> bis zum leerzeichen und alles danach ausgeben sonst weitergehen
	
	ifstream in;
	in.open("tagdb.txt");
	if (!in.is_open()) {
		cout << "Datei konnte nicht geoeffnet werden. Programm beenden...\n";
		exit(-1);
	}
	string line;

	while(getline(in, line)) {
		//for (auto &count : tags_v.size()) { //über bereichsbasierte for-loop informieren
		for (int count = 0; count < tags_v.size(); ++count) {
			if (line.find(tags_v[count]) != string::npos) {
				const size_t position_of_space = line.find(' ');
				const string content_to_print = line.substr(position_of_space + 1);//, (line.length() - ++position_of_space));
				cout << content_to_print << endl;	
			} else { //else-zweig noch implementieren
				//cout << "no corresponding tag found for " << tags_v[count] << endl;
			}
		}
	}	
}
