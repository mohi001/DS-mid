#ifndef HM
#define HM
#include <string>
#include <iostream>
std::string in_to_post(std::string str);
std::string in_to_pre(std::string in);
std::string post_to_in(std::string post);
std::string pre_to_post(std::string pre);
std::string post_to_pre(std::string str);
std::string pre_to_in(std::string str);
bool is_infix(std::string in);
bool is_postfix(std::string post);
bool is_prefix(std::string pre);
#include "Stack.cpp"
#endif