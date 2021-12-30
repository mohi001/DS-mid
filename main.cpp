#include "header.hpp"
int main(int argc, char const *argv[])
{
    std::string input = "";
    std::string exp = "";
    std::cout<<(is_infix(post_to_in("a b + +")));
    bool d = false;
    while (1 && d)
    {
        std::cout << "welcome,please chose a numebr\nor enter q to exit\n";
        std::cout << "1: infix to postfix\n";
        std::cout << "2: infix to prefix\n";
        std::cout << "3: postfix to infix\n";
        std::cout << "4: postfix to prefix\n";
        std::cout << "5: prefix to infix\n";
        std::cout << "6: prefix to postfix\n";
        std::getline(std::cin, input);
        if (input == "q" || input == "exit")
        {
            break;
        }
        int a = std::stoi(input);
        std::cout << "please inter your expresion:\n";

        std::getline(std::cin, exp);
        switch (a)
        {
        case 1:
            std::cout << in_to_post(exp);
            std::cout << "\n";
            break;
        case 2:
            std::cout << in_to_pre(exp);
            std::cout << "\n";
            break;
        case 3:
            post_to_in(exp);
            std::cout << "\n";
            break;
        case 4:
            post_to_pre(exp);
            std::cout << "\n";
            break;
        case 5:
            pre_to_in(exp);
            std::cout << "\n";
            break;
        case 6:
            pre_to_post(exp);
            std::cout << "\n";
            break;

        default:
            std::cout << "invalid";
            std::cout << "\n";
            break;
        }

        input = "q";
    }

    return 0;
}