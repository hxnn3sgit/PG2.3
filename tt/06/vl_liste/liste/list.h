#include <string>

namespace pg2 {
	class list {
		struct node {
			node *next;
			std::string value;
			node(const std::string &value);
		};
		node *head;
		node *current_position;
		
		void recursive_cleanup(node *n);

	public:
		list();
		~list();

		// list management
		void append(const std::string &value);
		void remove_current();

		// list traversal
		void start();
		bool at_valid_position();
		void next();
		const std::string& current_value();
	};
}
