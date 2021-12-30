#include "header.hpp"
std::string post_to_in(std::string post)
{
    std::string pre = post_to_pre(post);
    return pre_to_in(pre);
}