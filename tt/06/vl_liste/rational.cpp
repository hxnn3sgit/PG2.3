#include <iostream>

using std::cout, std::endl;

namespace pg2 {

	class rational {
		int num, denom;
	public:
		rational(int num, int denom = 1) : num(num), denom(denom) {
		}
		// 	rational(int num, int denom) {
		// 		this->num = num;
		// 		this->denom = denom;
		// 	}
		rational& mult(const rational &r) {
			num *= r.num;
			denom *= r.denom;
			return *this;
		}
		void print() {
			cout << num << "/" << denom << endl;
		}
	};

}

int main() {
	using namespace pg2;

	rational half(1, 2);
	rational quart(1, 4);

	rational two(2, 1);
	rational two2 = 2;


	half.mult(quart).mult(half).mult(10).print();
}
