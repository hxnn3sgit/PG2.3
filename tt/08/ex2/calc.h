#pragma once
#include "token.h"
#include <vector>
#include <cassert>

using namespace std;


bool syntax_check(const vector<token> &tokens);
double simple_eval_ltr(const vector<token> &tokens);
double calc_value(int left_number, char op, int right_number);
