#include "header.hpp"
static bool checkparentheses(std::string in);
static bool is_p(std::string s);
static bool is_operator(std::string str);
static Stack solve_minus(Stack in);

bool is_infix(std::string in)
{
    if (!checkparentheses(in))
    {
        return false;
    }
    Stack tmp(in);
    Stack st;
    std::string t;
    tmp = solve_minus(tmp);
    while(!tmp.isEmpty())
    {
        t = tmp.pop();
        if (!is_p(t))
        {
            st.push(t);
        }
    }
    st.reverse();
    
    t = st.pop();
    if (is_operator(t))
    {
        return false;
    }
    if (t == "..")
    {
        return false;
    }
    bool op = true;
    while (!st.isEmpty())
    {
        t = st.pop();
        if (t == "..")
        {
            return false;
        }

        if (is_operator(t) != op)
        {
            return false;
        }
        op = !op;
    }
    if (is_operator(t))
    {
        return false;
    }
    return true;
}
bool is_postfix(std::string post)
{
    std::string in = post_to_in(post, false);
    return is_infix(in);
}
bool is_prefix(std::string pre)
{
    std::string in = pre_to_in(pre, false);
    return is_infix(in);
}
static bool is_p(std::string s)
{
    return (s == "(" || s == ")");
}
static bool is_operator(std::string str)
{
    return str == "+" || str == "-" || str == "/" || str == "*" || str == "^" || str == "sin" || str == "cos" || str == "tan" || str == "cot";
}
static bool checkparentheses(std::string in)
{
    Stack st(in);
    Stack p;
    while (!st.isEmpty())
    {
        std::string t = st.pop();
        if (t == "(")
        {
            p.push(t);
        }
        else if (t == ")")
        {
            t = p.pop();
            if (!(t == "("))
            {
                return false;
            }
        }
    }
    if (p.isEmpty())
    {
        return true;
    }
    return false;
}
static Stack solve_minus(Stack in)
{
    std::string t;
    std::string c;
    Stack out;
    while (!in.isEmpty())
    {
        t = in.pop();
        if (t == "-")
        {
            c = out.peek();
            if (c == "(" || c == "sin" || c == "cos" || c == "tan" || c == "cot" || out.isEmpty())
            {
                out.push(in.pop() + " ?");
            }
            else
            {
                out.push(t);
            }
        }
        else
        {
            out.push(t);
        }
    }
    out.reverse();
    return out;
}