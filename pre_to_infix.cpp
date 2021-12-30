#include <string>
#include "Stack.cpp"

static bool is_operator(std::string str);
std::string pre_to_in(std::string str)
{
    std::cout << "prefix to infix: " << str << "\n";
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
        log(in, out);
    }
    return out.to_sring();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
static void log(Stack &in, Stack &out)
{
    std::cout << "input stack:\n";
    in.print();
    std::cout << "output stack:\n";
    out.print();
}