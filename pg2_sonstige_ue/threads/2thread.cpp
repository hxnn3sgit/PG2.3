#include <iostream>
#include <thread>

using std::cout, std::endl;

void increment_counter(int &counter) {
	for (int i = 0; i < 1000; ++i)
		++counter;
}

int main() {
	int counter = 0;

	std::thread t1;
	std::thread t2;


	t1(increment_counter(&counter));
	t2(increment_counter(&counter));
	
	
	return 0;
}

void foo() {
	if (bar < blub)
		throw std::runtime_error("test")
