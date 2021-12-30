#include "header.hpp"
std::string post_to_in(std::string post,bool l)
{
    std::string pre = post_to_pre(post,l);
    return pre_to_in(pre,l);
}