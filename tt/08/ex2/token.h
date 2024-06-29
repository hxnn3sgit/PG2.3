#pragma once

#include <vector>
#include <iostream>
#include <string>

class token {
public:
	enum kind { OP, NUM, VAR };
private:
	int number;
	char op;	// limitierend da char
	std::string name;
	//enum kind { OP, NUM, VAR };
	enum kind kind_of; //zuerst: enum kind kind;
public:
	token(int number) : number(number), kind_of(NUM) {}
	token(char op) : op(op), kind_of(OP) {}
	token(const std::string &name) : name(name), kind_of(VAR) {}
	kind wich_kind () const { return this->kind_of; } //aka getter vom kind
	int get_number() const { return this->number; }
	char get_operator() const { return this->op; }

	friend std::ostream& operator<<(std::ostream &out, const token &t);
};

std::vector<token> tokenize(std::istream &input);
