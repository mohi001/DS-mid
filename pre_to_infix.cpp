#include <string>
#include <iostream>
#include "Stack.cpp"

static bool is_operator(std::string str);
std::string pre_to_in(std::string str)
{
    Stack in(str);
    in.reverse();
    Stack out;
    std::string t;
    while (!in.isEmpty())
    {
        t = in.pop();
        if (is_operator(t))
        {
            std::string s1 = out.pop();
            std::string s2 = out.pop();
            out.push(std::string(" ") + "(" + " " + s1 + " " + t + " " + s2 + " " + ")" + " ");
        }
        else
        {
            out.push(t);
        }
    }
    out.printall();
    return out.to_sring();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
int main(int argc, char const *argv[])
{
    std::cout << pre_to_in("* +  A B - C D");

    return 0;
}
