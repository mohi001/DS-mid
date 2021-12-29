#include "header.hpp"
std::string in_to_pre(std::string in)
{
    std::string post = in_to_post(in);
    return post_to_pre(post);
}
// int main(int argc, char const *argv[])
// {
//     std::cout<<in_to_pre(" ( (  A + B ) * ( C - D ) ) ");

//     return 0;
// }

