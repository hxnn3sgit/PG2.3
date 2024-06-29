#include <ostream>

class dyn_arr {
private:
	int *data;
	unsigned int size;
public:
	dyn_arr() : size(0), data(nullptr) {}
	dyn_arr(unsigned int size) : size(size), data(new int[size]) {}
	~dyn_arr();
	int& at(unsigned int index);
	void push(int value);
	unsigned int length() { return size; }
	friend std::ostream& operator<<(std::ostream &out, const dyn_arr &my_arr);

};
