#include <iostream>

using std::cout, std::endl, std::cerr;

class linked_list_of_ints {
private:
	struct node{
		int value;
		node *next;
		node(const int data) : value(data), next(nullptr) {};
	};
	node *head;
public:
	linked_list_of_ints() : head(nullptr) {};
	linked_list_of_ints(int argc, char **args);
	~linked_list_of_ints();
	int len();
	void print();
	void append(int to_append);
	void prepend(int to_append);
	void insert_at(int value, int index);
};
