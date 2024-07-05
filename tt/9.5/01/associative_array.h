#pragma once

#include <vector>
#include <iostream>

template<typename VAL, typename KEY>
struct my_pair {
	VAL value;
	KEY key;
	my_pair(const VAL &value, const KEY &key) : value(value), key(key) {}
};

template<typename V, typename K>
class associative_array {
public:
	std::vector<my_pair<V, K>> data;
public:
	associative_array() {}
	associative_array(const V &value, const K &name);
	~associative_array() { data.clear(); }
   	void push(const V &value, const K &key);
	V operator[](const K &key) const;
	V& operator[] (const K &key);
	template<typename T, typename U>
	friend std::ostream& operator<<(std::ostream &out, const associative_array &other);   
};

#include "associative_array_impl.h"
