#include "dyn_arr.h"
#include <iostream>


using std::endl, std::cout, std::cerr;

dynamic_array::dynamic_array() : data(nullptr), size(0), capacity(0) {}

dynamic_array::dynamic_array(int to_alloc) : data(new int[to_alloc]), size(to_alloc), capacity(to_alloc) {}

dynamic_array::~dynamic_array() {
	cout << __PRETTY_FUNCTION__ << endl;
	delete [] data;
}

int& dynamic_array::at(int i) {
	return data[i];
}

unsigned int dynamic_array::len() {
	return size;
}

void dynamic_array::print_array() {
	cout << "[";
	for (unsigned int i = 0; i < size; ++i) {
		cout << data[i] << " ";
	}
	cout << "]" << endl;
}

void dynamic_array::push(int x) {
	int new_size = size + 1;
	int *new_data = new int[new_size];

	for (unsigned int i = 0; i < size; ++i)
		new_data[i] = data[i];

	new_data[new_size-1] = x;
	size = new_size;

	delete [] data;
	data = new_data;
}

void dynamic_array::reserve(unsigned int n) {
	if (n <= size) { //nix tun
		return;
	}

	//mehr Speicher reservieren
	int *new_data = new int[n];

	//rüberkopieren
	for (unsigned int i = 0; i < size; ++i) {
		new_data[i] = data[i];
	}

	//capacity und data auf andere Größe umspeichern
		delete [] data;
	data = new_data;
	capacity = n;

	//temporäre daten löschen; //muss man nicht... warum??
	//delete [] new_data;
	
	

}
