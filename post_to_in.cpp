#include"header.hpp"
std::string post_to_in(std::string post)
{
    std::string pre = post_to_pre(post);
    return pre_to_in(pre);
}
// int main(int argc, char const *argv[])
// {
//     std::cout<<post_to_in("a b * c +");

//     return 0;
// }