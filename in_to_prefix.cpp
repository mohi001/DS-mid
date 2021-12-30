#include "header.hpp"
std::string in_to_pre(std::string in)
{
    std::string post = in_to_post(in);
    return post_to_pre(post);
}