#include <iostream>
#include <string>

using namespace std;

class A {
public:
    int my_int;
    A() : my_int(0) { cout << __PRETTY_FUNCTION__ << endl; }
    A(int my_int) : my_int(my_int) { cout << __PRETTY_FUNCTION__ << endl; }
    ~A() { cout << __PRETTY_FUNCTION__ << endl; }
};

class B : public A {
public:
    string my_string;
    //B(int i) : my_int(i) { cout << __PRETTY_FUNCTION__ << endl; }
    B(const string &s) : my_string(s) { cout << __PRETTY_FUNCTION__ << endl; }
    ~B() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main() {
    A a(1);
    B b("b");    
    //b.my_int = 2;
    cout << "a.int: " << a.my_int << endl;
    cout << "b.int: " << b.my_int << ", b.my_string: " << b.my_string << endl;

    return 0;
}