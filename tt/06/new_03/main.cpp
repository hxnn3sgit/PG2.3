#include <iostream>
#include "linked_list_of_ints.h"
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) {
	linked_list_of_ints arg_list(argc, argv);
	cout << "arg_list: \n" << arg_list << endl;	
	}

	linked_list_of_ints list_one;
	//appending things on list: 17ms
	for (int i = 1; i < 6; ++i)
	   list_one.append(i);
	cout << "first List:\n";
	list_one.insert_at(32324, 3);
	cout << list_one << endl;

	//c c'tor demo:
	linked_list_of_ints copied_list(list_one);
	cout << "copied list:\n" << copied_list << endl;

	//move c'tor demo:
	linked_list_of_ints my_first_list;
	linked_list_of_ints my_second_list;
	for (int i = 10; i < 21; ++i)
		my_first_list.append(i);

	cout << "before move:\nfirst: \n" << my_first_list << endl << my_second_list << endl;
	my_second_list(std::move(my_first_list));
	cout <<"after move:\nfirst: \n" << my_first_list << endl << my_second_list << endl;

	return 0;
}
