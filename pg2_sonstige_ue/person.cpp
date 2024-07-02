#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person() : name(""), age(0) { cout << __PRETTY_FUNCTION__ << endl; }
    Person(const string &name, int age) : name(name), age(age) { cout << __PRETTY_FUNCTION__ << endl; }
    void print_info() {
        cout << name << " ist " << age << " Jahre alt" << endl;
    }
};

class Student : public Person {
private:
    int studendID;

}

int main() {

    return 0;
}