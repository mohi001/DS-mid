#include <string>
#include "Stack.cpp"
static bool is_operator(std::string str);
static void log(Stack &in, Stack &out, bool l);

std::string pre_to_in(std::string str, bool l)
{
    if (l)
    {
        std::cout << "prefix to infix: " << str << "\n";
    }
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
        log(in, out, l);
    }
    return out.to_sring();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
static void log(Stack &in, Stack &out, bool l)
{
    if (l)
    {

        std::cout << "input stack:\n";
        in.print();
        std::cout << "output stack:\n";
        out.print();
    }
}