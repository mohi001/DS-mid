#include "header.hpp"
std::string pre_to_post(std::string pre)
{
    std::string in = pre_to_in(pre);
    return in_to_post(in);
}