#include <iostream>

using namespace std;

class PiggyBank {
private:
	int c_001, c_010, c_050, c_100;
	int max_c_muenzen;
	bool piggy_broken;
public:
	PiggyBank(int max_muenzen) : c_001(0), c_010(0), c_050(0), c_100(0), max_c_muenzen(max_muenzen), piggy_broken(false) {}
	
	int add1Cents(int to_throw) {
		if ( (coins_in_pig() + to_throw) <= max_c_muenzen) {
			c_001 += to_throw;
			return 0;
		} else {
			int count = 1;
			while ( c_001++ <= max_c_muenzen) {
				count++;
			}
			c_001 += count;
			return to_throw - count;
		}
	}
	/*int add10Cents(int to_throw) { ++c_010; }
	int add50Cents(int to_throw) { ++c_050; }
	int add1Euros(int to_throw) { ++c_100; }*/

	bool isEmpty() {
		if (c_001 == 0 && c_010 == 0 && c_050 == 0 && c_100 == 0)
			return true;
		else
			return false;
	}

	bool isFull() {
		if (c_001 + c_010 + c_050 + c_100 >= max_c_muenzen)
			return true;
		else
			return false;
	}

	int coins_in_pig() { return c_001 + c_010 + c_050 + c_100; }

	bool isBroken() { return piggy_broken; }
	int breakInto() {}
};

int main() {
	PiggyBank my_piggy(4);

	my_piggy.add1Cents(1);
	my_piggy.add1Cents(2);

	cout << "coins in my pig: " << my_piggy.coins_in_pig() << endl;

	cout << "too much?: " << my_piggy.add1Cents(6) << endl;

	cout << my_piggy.coins_in_pig() << endl;

	if (my_piggy.isFull())
		cout << "full\n";
	else
		cout << "empty\n";

	return 0;
}
