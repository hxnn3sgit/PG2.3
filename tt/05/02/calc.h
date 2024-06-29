#pragma once

#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <sstream>

namespace math {
	float calc(const char op, const int left, const int right);
	bool valid_op(const char op);
	float calc(const std::string &args);
	float calc();
}
