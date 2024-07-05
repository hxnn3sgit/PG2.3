template<typename T>
class dynamicArray {
private:
	T *value;
	unsigned int size;
public:
	dynamicArray() : size(0), value(nullptr) {}
	dynamicArray(int size) : size(size), value(new T[size]) {}
	dynamicArray(initializer_list<T> init_list);
	~dynamicArray();
	T& at(int i) const;
	void push(const T &x)
		T& at(int i) const;
	void push(const T &x);
	T& operator=(const T &my_arr);
	bool operator==(const;
	T& operator=(const T &my_arr);
	bool operator==(const

}
