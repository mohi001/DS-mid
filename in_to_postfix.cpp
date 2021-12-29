#include "header.hpp"

static bool is_operator(std::string str);
static bool is_pop_op(std::string input_op, std::string operand_op);

std::string in_to_post(std::string str)
{
    Stack in(str);
    Stack out;
    Stack operat;
    std::string t;
    while (!in.isEmpty())
    {
        t = in.pop();
        if (is_operator(t))
        {
            while (!operat.isEmpty() && is_pop_op(t, operat.peek()))
            {
                out.push(operat.pop());
            }
            operat.push(t);
        }
        else
        {
            if (t == ")")
            {
                while (operat.peek() != "(")
                {
                    out.push(operat.pop());
                }
                operat.pop();
            }
            else if (t == "(")
            {
                operat.push(t);
            }
            else
            {
                out.push(t);
            }
        }
    }
    while (!operat.isEmpty())
    {
        out.push(operat.pop());
    }
    return out.to_sring();
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^";
}
static int prec(std::string c)
{
    if (c == "^")
        return 3;
    else if (c == "/" || c == "*")
        return 2;
    else if (c == "+" || c == "-")
        return 1;
    else
        return -1;
}
static bool is_pop_op(std::string input_op, std::string operand_op)
{
    int in_perc = prec(input_op);
    int op_perc = prec(operand_op);
    if (in_perc < op_perc)
    {
        return true;
    }
    if (in_perc > op_perc)
    {
        return false;
    }
    if (in_perc == op_perc)
    {
        if (operand_op == "^")
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return false;
}
// int main(int argc, char const *argv[])
// {
//     std::cout << in_to_post("(  A + B ) * ( C - D )");

//     return 0;
// }