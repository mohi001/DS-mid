#include <string>
#include<iostream>
#include "Stack.cpp"
static bool is_operator(std::string str);
std::string post_to_pre(std::string str)
{
    Stack in(str);
    Stack out;
    std::string t;
    while (!in.isEmpty())
    {
        t = in.pop();
        if (is_operator(t))
        {
            t = t + " " + out.pop() + " " + out.pop();
            out.push(t);
        }
        else
        {
            out.push(t);
        }
    }
    return out.to_sring();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
int main(int argc, char const *argv[])
{
    std::cout<<post_to_pre("a b + c - d e f ^ ^ * g /");
    return 0;
}
