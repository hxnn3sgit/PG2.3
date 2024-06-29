#include "list.h"

#include <cassert>

namespace pg2 {

	list::node::node(const std::string &value) {
		next = nullptr;
		this->value = value;
	}

	list::list() {
		head = nullptr;
		current_position = nullptr;
	}

	void list::recursive_cleanup(list::node *n) {
		if (n) {
			recursive_cleanup(n->next);
			delete n;
		}
	}

	list::~list() {
#define VARIANTE_3
#ifdef VARIANTE_1
		while (head) {
			node *to_delete = head;
			head = head->next;
			delete to_delete;
		}
#elif defined(VARIANTE_2)
		start();
		while (head)
			remove_current();
#else
		recursive_cleanup(head);
#endif
	

	}

	void list::append(const std::string &value) {
		// neuen knoten aufsetzen
		node *to_append = new node(value);

		if (head) {
			// ende der liste finden
			node *run = head;
			while (run->next) run = run->next;
			// jetzt zeigt run auf das letzte element
			run->next = to_append;
		}
		else
			head = to_append;
	}

	void list::remove_current() {
		assert(at_valid_position());
		if (current_position == head) {
			head = head->next;
			delete current_position;
			current_position = head;
		}
		else {
			node *run = head;
			while (run->next != current_position) run = run->next;
			run->next = current_position->next;
			delete current_position;
			current_position = run->next;
		}
	}

	void list::start() {
		current_position = head;
	}

	bool list::at_valid_position() {
		return current_position != nullptr;
	}

	void list::next() {
		assert(at_valid_position());
		current_position = current_position->next;
	}

	const std::string& list::current_value() {
		assert(at_valid_position());
		return current_position->value;
	}

}
