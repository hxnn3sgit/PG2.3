#include <iostream>
#include <vector>

using namespace std;

enum kind {
	OP,
	NUM,
	VAR
};

class token {
private:
	int number;
	char op;
	kind kind_of;
public:
	token(int number) : number(number), kind_of(NUM) {}
	token(char op) : op(op), kind_of(OP) {}
	kind wich_kind() {return this->kind_of; }

	//friend std::ostream& operator<<(std::ostream &out, const token &c) {
	//	return out << "[" << c << "]";
	//}

};

int main() {
	vector<token> t;	
	
	t.push_back(1);
	t.push_back('+');
	t.push_back('2');
	t.push_back('+');
	t.push_back('3');

	//cout << t << endl;

	for (int i = 0; i < t.size(); ++i)
		cout << t[i]<< endl;
	
	return 0;
}
