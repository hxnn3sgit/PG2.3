#include <iostream>
#include <exception>
#include <cmath>
using namespace std;

template < typename T > struct d_arr {
    T * data ;
    int size ;
     d_arr () : data (0) , size (0) {}
    d_arr ( const d_arr & other );
    ~d_arr () { delete [] data ; }
    void append ( const T & element );
};

struct price_missmatch : public std::exception {
    const char* what() const noexcept override { return "prices doesn´t match"; }
};

struct missing_price : public std::exception {
    const char* what() const noexcept override { return "no price specified!" ;}
};

struct inventory_entry {
    string producer;
    string prod_name;
    int quantity;
    float price;
    inventory_entry(const string &producer, const string &prod_name, int quantity, float price) : 
                    producer(producer), prod_name(prod_name), quantity(quantity), price(price) {}
};

class inventory {
private:
    d_arr<inventory_entry> my_inventory;
public:
    inventory() = default;
    ~inventory() = default;
    //c ctor
    inventory(const inventory &other) = delete;
    inventory& operator=(const inventory &other) = delete;
    //move ctor
    inventory(inventory &&other) noexcept;
    inventory& operator=(inventory &&other);

    void add_item(const string &hersteller, const string &prod_name, float price=-1.0);
};

inventory::inventory(inventory &&other) noexcept {
    my_inventory = other.my_inventory;
    other.my_inventory.data = nullptr;
    other.my_inventory.size = 0;
}

inventory& inventory::operator=(inventory &&other) {
    if (this != &other) {//self check
        delete [] my_inventory.data;
        my_inventory = other.my_inventory;
        other.my_inventory.data = nullptr;
        other.my_inventory.size = 0;
    }
    return *this;
}

bool are_equal(float price, float epsilon = 1e-6) {
    return std::fabs(-1.0 - price) < epsilon;
}

void inventory::add_item(const string &hersteller, const string &prod_name, float price = -1.0) {
    for (int i = 0; i < my_inventory.size; ++i) {
        if (my_inventory.data[i].producer == hersteller && my_inventory.data[i].prod_name == prod_name) {
            if (are_equal(price)) //price is -1.0 -> no price is defined
                throw price_missmatch();
            else
                my_inventory.data[i].quantity += 1;
        } else {
            if (price == -1.0)
                throw missing_price();
            else
                my_inventory.append(inventory_entry(hersteller, prod_name, 1, price));
        }
    }
}

int main() {

    return 0;
}
