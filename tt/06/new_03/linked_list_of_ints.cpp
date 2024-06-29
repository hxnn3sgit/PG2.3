#include "linked_list_of_ints.h"
#include <iostream>
#include <cassert>

using std::cout, std::endl, std::cerr;
using namespace std;

linked_list_of_ints::linked_list_of_ints(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		this->append(atoi(argv[i]));
	}	
}

linked_list_of_ints::~linked_list_of_ints() {
	//delete all nodes
	node *current = head;
	while (current != nullptr) {
		node *temp = current;
		current = current->next;
		delete temp;
	}
}

int linked_list_of_ints::len() {
	int len = 0;
	node *run = head;
	while (run != nullptr) {
		len++;
		run = run->next;
	}
	return len;
}

void linked_list_of_ints::print() {

	if (head == nullptr) {
		cout << "Die Liste ist leer\n";
	} else {
		node *current = head;
		cout << "|--";
		while (current != nullptr) {
			cout << current->value << "--";
			current = current->next;
		}
		cout << "|\n";
	}
}

void linked_list_of_ints::append(int to_append) {
	if (head != nullptr) {
		node *new_node = new node(to_append);
		node *run = head;

		while (run->next != nullptr) {
			run = run->next;
		}

		run->next = new_node;
	} else { //head == nullptr
		node *new_node = new node(to_append);
		head = new_node;
	}
}

void linked_list_of_ints::prepend(int to_append) {
	node *new_node = new node(to_append);

	if (head == nullptr) {
		head = new_node;
	} else {
		new_node->next = head;
		head = new_node;
	}
}

void linked_list_of_ints::insert_at(int value, int index) {
	assert(index < this->len() && "Index out of bounds");
	node *new_node = new node(value);
	node *current = head;
	for (int i = 1; i < index; ++i) {
		current = current->next;
	}
	new_node->next = current->next;
	current->next = new_node;
	
	//delete current; Löschen, warum?	

}

//ostream operator überladen:
std::ostream& linked_list_of_ints::operator<<(ostream &out, const linked_list_of_ints &list) {
	out << "|";
	for (int i = 0; i < this->len(); ++i)
		out << head->value << "--";
	out << "|" << endl;
	return out;
}
