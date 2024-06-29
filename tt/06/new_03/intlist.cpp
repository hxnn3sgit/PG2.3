#include <iostream>

using namespace std;

class list {
private:
	struct node {
		int value;
		node *next;
		node(int data) : value(data), next(nullptr) {}
	};
	node *head; //des brauchtma aber ka why
	
public:
	list() : head(nullptr) {} //Konstruktor, erzeugt leere liste
	~list() {

	   	node *run = head;
		node *temp;
		while(run != nullptr) {
			temp = run;
			run = run->next;
			delete temp;
		}
		delete run;
  	}
	
	void insert_at_beginning(int data) {
		node *new_node = new node(data);
		new_node->next = head; //this->head müsste auch gehen -> ausprobieren
		head = new_node;
	 }

	void print() {
		node *current = head;
		cout << "|--";
		while (current != nullptr) {
			cout << current->value << "--";
			current = current->next;
		}
		cout <<"|" << endl;
	}

	

};


int main(int argc, char **argv) {
	
	list new_list;

	new_list.insert_at_beginning(43);
	new_list.insert_at_beginning(3423);
	new_list.insert_at_beginning(132);

	for (int i = 1; i < argc; ++i){
		new_list.insert_at_beginning(atoi(argv[i]));
	}

	new_list.print();

	return 0;
}
