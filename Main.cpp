#include<iostream>
#include<string>
#include<array>
#include"Stack.cpp"
int main(int argc, char const *argv[])
{
    Stack s("1   25 + 6");
    s.printall();
    std::cout<<s.pop();
    return 0;
}
