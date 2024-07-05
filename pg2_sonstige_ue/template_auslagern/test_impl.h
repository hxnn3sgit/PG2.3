#pragma once
#include <iostream>
using std::cout, std::endl;
template<typename T>
inhalt<T>::inhalt(const T &inhalt) : data_inhalt(inhalt) { cout << __PRETTY_FUNCTION__ << inhalt << endl; }

template<typename T>
void inhalt<T>::print_inhalt() { cout << "inhalt: " << data_inhalt << endl; }
