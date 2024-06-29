template<typename T, typename K>
class associative_array {
private:
	T *data;
	K key ;
public:
	associative_array() : key(), data(nullptr) {}
	associative_array(unsigned int size) : size(size), data(new T[size]) {}
	~associative_array();

};
