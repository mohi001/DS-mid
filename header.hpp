#ifndef HM
#define HM
#include <string>
#include <iostream>
std::string in_to_post(std::string str);
bool is_infix(std::string in);
std::string post_to_pre(std::string str);
std::string pre_to_in(std::string str);
#include "Stack.cpp"
#endif