#include <iostream>
#include <string>
#define MAX 100
class Stack
{
private:
    std::string arr[MAX];
    unsigned int m_size;

public:
    Stack()
    {
        m_size = 0;
    };
    Stack(std::string str)
    {
        m_size = 0;
        std::string tmp = "";
        char del = ' ';
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] != del)
            {
                tmp += str[i];
            }
            else
            {
                if (tmp != "")
                    push(tmp);
                tmp = "";
            }
        }
        if (tmp != "")
            push(tmp);
        //reverse stack
        reverse();
    }
    bool push(std::string x)
    {
        if (m_size < MAX)
        {
            arr[m_size] = x;
            m_size++;
            return true;
        }
        else
            return false;
    }
    std::string pop()
    {
        if (m_size)
        {
            m_size--;
            return arr[m_size];
        }
        else
        {
            // std::cout << "stack is empty\n";
            return "..";
        }
    }
    std::string peek()
    {
        if (m_size)
        {
            return arr[m_size - 1];
        }
        else
        {
            // std::cout << "stack is empty\n";
            return "..";
        }
    }
    bool isEmpty()
    {
        return !m_size;
    }
    unsigned int size()
    {
        return m_size;
    }
    void reverse()
    {
        std::string tmp;
        for (size_t i = 0; i < m_size / 2; i++)
        {
            tmp = arr[i];
            arr[i] = arr[m_size - 1 - i];
            arr[m_size - 1 - i] = tmp;
        }
    }
    void print()
    {
        std::string tmp = "[ ";
        for (size_t i = 0; i < m_size; i++)
        {
            tmp += arr[i] + ", ";
        }
        tmp += "]\n";
        std::cout << tmp;
    }
    std::string to_string()
    {
        std::string tmp;

        for (size_t i = 0; i < m_size; i++)
        {
            tmp += arr[i] + " ";
        }
        return tmp;
    }
};