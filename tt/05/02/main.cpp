#include "calc.h"

using namespace std;

int main(int argc, char **argv) {
	if (argc == 4) {
		if (math::valid_op(argv[2][0]))
			cout << math::calc(argv[2][0], atoi(argv[1]), atoi(argv[3])) << endl;
		else
			std::cerr << "Ungueltiges Rechenzeichen. Gueltige Zeichen: +, -, *, /\n";
	} else if (argc == 2) {
		//wenn rechnung in argv[1] ist
		string rechnung = argv[1];
	   cout << math::calc(rechnung) << endl;
	} else if (argc == 1) {
		//von stdin einlesen
		cout << math::calc() << endl;
	} else {
		std::cerr << "Ungueltige Uebergabeparameter. Programm beenden...\n";
		return -1;
	}


	return 0;
}
