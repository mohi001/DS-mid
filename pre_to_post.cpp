#include "header.hpp"
std::string pre_to_post(std::string pre, bool l)
{
    std::string in = pre_to_in(pre, l);
    return in_to_post(in, l);
}