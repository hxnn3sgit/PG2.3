

template<typename T>
class dynamic_array {
private
	T* data;
	int size;
	int capacity;
public:
	dynamic_array() : data(nullptr), size(0), capacity(0) {}
	dynamic_array(int size) : data(new T[size], size(size), capacity(size) {}
	~dynamic_array();
	void push(const T &value);
	T operator[](int index);
	
	template<typename O>
	friend std::ostream& operator<<(std::ostream &out, const O &other);	
};
