#include <iostream>

using std::cout, std::endl, std::cerr;

class linked_list_of_ints {
private:
	struct node{
		int value;
		node *next;
		node(const int value) : value(value), next(nullptr) {};
	} node;
	node *head;
public:
	linked_list_of_ints();
	linked_list_of_ints(int argc, char **args);
	~linked_list_of_ints();
	void print();
	void append(int to_append);
};
