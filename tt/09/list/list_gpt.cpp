#include <iostream>
#include <cstdlib>

using std::cout, std::endl;

template<typename T>
class list {
private:
    struct node {
        T value;
        node *next;
        node(const T &data) : value(data), next(nullptr) {}
    };
    node *head;
public:
    list() : head(nullptr) {}
    ~list();
    int len() const;
    void append(const T &to_append);
    void prepend(const T &to_prepend);
    void insert_at(const T &value, int index);

    template<typename U>
    friend std::ostream& operator<<(std::ostream &out, const list<U> &lst);
};

template<typename T>
list<T>::~list() {
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
}

template<typename T>
void list<T>::prepend(const T &to_prepend) {
    node *new_node = new node(to_prepend);
    new_node->next = head;
    head = new_node;
}

template<typename U>
std::ostream& operator<<(std::ostream &out, const list<U> &lst) {
    typename list<U>::node *run = lst.head;
    while (run) {
        out << "[" << run->value << "]--";
        run = run->next;
    }
    out << "]";
    return out;
}

int main(int argc, char **argv) {
    list<int> my_list;

	cout << "List len: " << my_list.len() << endl;

    for (int i = 1; i < argc; ++i)
        my_list.prepend(atoi(argv[i]));

    cout << my_list << endl;

    return 0;
}
