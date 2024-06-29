#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

template<typename T>
class list {
private:
	struct node {
		T value;
		node *next;
		node(const T &data) : value(data), next(nullptr) {};
		node() : value(), next(nullptr) {};
	};
	node *head;
public:
	list() : head(nullptr) {};
	list(const list &other); //c ctor
	//list(list &&other); //move ctor
	~list();
	int len() const;
	void append(const T &to_append);
	void prepend(const T &to_prepend);
	void insert_at(const T &value, int index);
	void delete_item(const T &value);
	//list &operator=(list other); //assigment
	template<typename U>
	friend std::ostream& operator<<(std::ostream &out, const list<U> &my_list); 
};

class car {
private:
	string marke;
	int vMax;
public:
	car() {}
	car(int vMax, string marke) : vMax(vMax), marke(marke) {}
	//destruktor wird nicht benötigt
	bool operator==(const car &other);
	bool operator!=(const car &other);
	friend ostream &operator<<(ostream &out, const car &my_car);
};

bool car::operator==(const car &other) {
	if (marke == other.marke && vMax == other.vMax)
		return true;
	else
		return false;
}

bool car::operator!=(const car &other) {
	if (marke != other.marke && vMax != other.vMax)
		return true;
	else
		return false;
}

ostream &operator<<(ostream &out, const car &my_car) {
	out << "marke: " << my_car.marke << ", vMax: " << my_car.vMax;
	
	return out;
}

template<typename T>
list<T>::list(const list &other) {
	node *run = other.head;
	while (run) {
		append(run->value);
		run = run->next;
	}
}

/*template<typename T>
list<T>::list(list &&other) noexcept : head(other.head) {
	other.head = nullptr;
}*/

template<typename T>
list<T>::~list() {
	node *current = head;
	while(current) {
		node *next = current->next;
		delete current;
		current = next;
	}
	delete current;
}

template<typename T>
int list<T>::len() const {
	node *run = head;
	int count = 0;
	while (run) {
		++count;
		run = run->next;
	}
	
	return count;
}

template<typename T>
void list<T>::append(const T &to_append) {
	if (head != nullptr) {
		node *new_node = new node(to_append);
		node *run = head;

		while (run->next) {
			run = run->next;
		}
		run->next = new_node;	
	} else {
		node *new_node = new node(to_append);
		head = new_node;
	}
}

template<typename T>
void list<T>::prepend(const T &to_prepend) {
	node *new_node = new node(to_prepend);
	new_node->next = head;
	head = new_node;
}

template<typename T>
void list<T>::delete_item(const T &value) {
	if(head->value == value) { //head must be deleted
		node *temp = head;
		head = head->next;
		delete temp;
		return;
	} else {	
		node *run = head;
		node *prev = nullptr;
		while(run->value != value && run != nullptr) {	
			prev = run;
			run = run->next;
		}
		
		if (!run)
			return;
		prev->next = run->next;
		delete run;
	}	
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const list<T> &my_list) {
	if (my_list.head) {
		typename list<T>::node *run = my_list.head;
		while (run) {
			out << "[" << run->value << "]--";
			run = run->next;
		}
		out << "|";

		return out;	
	} else
		return out << "list is empty";
}

void do_things_with_cars() {
	car car1(241, "VW");
	car car2(400, "Bugatti");
	car car3(220, "Opel");
	car car4(280, "Audi");

	list<car> my_list_of_cars;

	my_list_of_cars.prepend(car1);
	my_list_of_cars.prepend(car2);
	my_list_of_cars.prepend(car3);
	my_list_of_cars.prepend(car4);

	cout << my_list_of_cars << endl;
	my_list_of_cars.delete_item(car1);
	cout << my_list_of_cars << endl;
}

void do_things_with_ints(int argc, char **argv) {
	list<int> my_int_list;
	if (argc > 1) {
		for (int i = 1; i < argc; ++i)
			my_int_list.prepend(atoi(argv[i]));
		cout << my_int_list << endl;
	}
}

void do_things_with_strings() {
	string string1 = "hallo";
	string string2 = "das";
	string string3 = "ist";
	string string4 = "test";
	string string5 = "ein";

	list<string> my_list_of_strings;

	my_list_of_strings.append(string1);
	my_list_of_strings.prepend(string2);
	my_list_of_strings.append(string3);
	my_list_of_strings.prepend(string4);
	my_list_of_strings.append(string5);

	cout << my_list_of_strings << endl;
	
	my_list_of_strings.delete_item("das");

	cout << my_list_of_strings << endl;
}

int main(int argc, char **argv) {
	do_things_with_ints(argc, argv);
	do_things_with_cars();
	do_things_with_strings();
}
