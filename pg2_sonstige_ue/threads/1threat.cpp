#include <iostream>
#include <thread>

using std::cout, std::endl, std::string;

void thread_function() {
	cout << "Hello from thread" << endl;
}

int main() {

	std::thread my_thread(thread_function);
	cout << "Hello from main" << endl;

	my_thread.join();

	return 0;
}
