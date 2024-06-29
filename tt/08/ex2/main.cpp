#include "token.h"
#include "calc.h"
#include <sstream>

using namespace std;

int main() {
	/*vector<token> tokens = tokenize(cin);

		if (syntax_check(tokens)) {
			cout << "Ergebnis: " << simple_eval_ltr(tokens) << endl;
		} else {
			cout << "Syntax falsch. Programm beenden...\n";
			exit(-1);
		}*/

	vector<token> tokens;
	string line;
	stringstream ss;
	int line_number = 1;



	while (true) {
		tokens = tokenize(cin);
		
		if (tokens.empty())
			break;
		
		if (syntax_check(tokens)) 
				cout << "Ergebnis: " << simple_eval_ltr(tokens) << endl;
			 else {
				cout << "Syntax falsch. Programm beenden...\n";
				exit(-1);
			}
	
		//cerr << "Falsche Eingabe in Zeile " << line_number << endl;
		//++line_number;	
	}
	return 0;
}
