#include "header.hpp"
int main(int argc, char const *argv[])
{
    std::cout << "welcome\n";
    std::string input = "";
    std::string exp = "";
    std::string str = "";
    while (1)
    {
        std::cout << "please chose a numebr\nor enter q to exit\n";
        std::cout << "1: convert expresiones\n";
        std::cout << "2: sort\n";
        std::getline(std::cin, input);
        if (input == "q" || input == "exit")
        {
            std::cout << "bye...";
            break;
        }
        int a = std::stoi(input);
        if (std::system("clear"))
        {
            fprintf(stderr, "faild to clear \n");
        };
        switch (a)
        {
        case 1:
            convert();
            break;
        case 2:
            sort();
            break;
        default:
            std::cout << "invalid";
            std::cout << "\n";
            break;
        }
    }
    return 0;
}