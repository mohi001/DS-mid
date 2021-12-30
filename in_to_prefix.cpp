#include "header.hpp"
std::string in_to_pre(std::string in,bool l)
{
    std::string post = in_to_post(in,l);
    return post_to_pre(post,l);
}