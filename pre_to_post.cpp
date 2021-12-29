#include "header.hpp"
std::string pre_to_post(std::string pre)
{
    std::string in = pre_to_in(pre);
    return in_to_post(in);
}
// int main(int argc, char const *argv[])
// {
//     std::cout<<pre_to_post("");

//     return 0;
// }