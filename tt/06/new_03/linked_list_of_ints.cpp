#include "linked_list_of_ints.h"
#include <iostream>
#include <cassert>

using std::cout, std::endl, std::cerr;
using namespace std;

linked_list_of_ints::linked_list_of_ints(int argc, char **argv) : head(nullptr) {
	for (int i = 1; i < argc; ++i) {
		this->append(atoi(argv[i]));
	}	
}

linked_list_of_ints::linked_list_of_ints(const linked_list_of_ints &other) : head(nullptr) {
	if (other.head == nullptr) { //liste die kopiert werde soll, ist leer
		head = nullptr;
	} else {
		head = new node(other.head->value);
		node *current = head;
		node *other_current = other.head->next;
		while (other_current != nullptr) {
			current->next = new node(other_current->value);
			current = current->next;
			other_current = other_current->next;
		}
	}
}

linked_list_of_ints::linked_list_of_ints(linked_list_of_ints &&other) noexcept : head(nullptr){
	if (other.head == head) {
		return;
	}
	head = other.head;
	other.head = nullptr;
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
std::ostream& operator<<(ostream &out, const linked_list_of_ints &my_list) {
	//int len = my_list.len();
	out << "|";
	linked_list_of_ints::node *current = my_list.head;
	while(current) {
		out << current->value << "--";
		current = current->next;
	}
	out << "|" << endl;
	return out;
}
