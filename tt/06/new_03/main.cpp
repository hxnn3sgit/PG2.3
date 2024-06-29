#include <iostream>
#include "linked_list_of_ints.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	
	linked_list_of_ints list_one;
	//appending things on list: 17ms
	
	for (int i = 1; i < 101; ++i)
	   list_one.append(i);
	cout << "first List:\n";
	list_one.insert_at(32324, 3);
	cout << list_one << endl;

	/*//prepending things on list: 0,065 ms :() 
	linked_list_of_ints list_two;
	ofstream of("listestream.txt"); //todo: operator für filestream überladen
	for (int i = 1; i < 101; ++i) {
		list_two.prepend(i);
	}
	list_two.print();
	cout << "listlen: " << list_two.len() << endl;

	list_two.insert_at(9999, 4);*/

	return 0;
}
