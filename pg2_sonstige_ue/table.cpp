#include <iostream>
#include <string>

class table {
private:
	struct col {
		int *cols;	
	};
	struct row {
		col *cols = nullptr;
	};
	row *rows = nullptr;
public:
	int w, h;
	table(int w, int h) : w(w), h(h) {
		rows = new int[w];
		row.cols = new int[h];
	}
	
};

int main() {

	return 0;
}
