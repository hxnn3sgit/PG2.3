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
   		
	template<typename X>
	class iterator {
	public:
		typename std::vector<my_pair<V, K>>::iterator iter;
	public:
		iterator(typename std::vector<my_pair<V, K>>::iterator it) : iter(it) {}
		my_pair<V, K>& operator*() { return *iter; }
		iterator& operator++() { ++iter; return *this; }
		bool operator==(const iterator &other) {
			return iter == other.iter;
		}
		bool operator!=(const iterator &other) {
			return iter != other.iter;
		}
	};

	iterator begin() { return iterator(data.begin()); }
	iterator end() { return iterator(data.end()); }
};

#include "associative_array_impl.h"
