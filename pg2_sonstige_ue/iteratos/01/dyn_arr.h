
class dynamic_array {
private:
	int *data;
	unsigned int size;
	unsigned int capacity;
public:
	dynamic_array();	
	dynamic_array(int to_alloc);
	~dynamic_array();
	int &at(int i);
	unsigned int len();
	void print_array();
	void push(int x);
	void reserve(unsigned int n);
};

