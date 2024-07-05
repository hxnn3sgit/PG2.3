#include "test.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	inhalt<int> mein_int_inhalt(10);
	mein_int_inhalt.print_inhalt();

	inhalt<string> mein_string_inhalt("Das ist ein Test");
	mein_string_inhalt.print_inhalt();

	return 0;
}
