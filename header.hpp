#ifndef HM
#define HM
#include <string>
#include <iostream>
std::string in_to_post(std::string str, bool l);
std::string in_to_pre(std::string in, bool l);
std::string post_to_in(std::string post, bool l);
std::string pre_to_post(std::string pre, bool l);
std::string post_to_pre(std::string str, bool l);
std::string pre_to_in(std::string str, bool l);
bool is_infix(std::string in);
bool is_postfix(std::string post);
bool is_prefix(std::string pre);
#include "Stack.cpp"
#include "fix_to_fix.cpp"
#endif