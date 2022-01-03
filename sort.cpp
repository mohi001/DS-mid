#include <iostream>
static void back_to_menu();

int *get_arr(std::string str, int &size)
{
    int *arr = new int[200];
    size = 0;
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
                arr[size] = std::stoi(tmp);
            size++;
            tmp = "";
        }
    }
    if (tmp != "")
    {
        arr[size] = std::stoi(tmp);
        size++;
    }
    return arr;
}
void swap(int &xp, int &yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}
void bubble_sort(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}
void selection_sort(int *arr, int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int min_i = j;
        for (int i = j + 1; i < size; i++)
        {
            if (arr[min_i] > arr[i])
            {
                min_i = i;
            }
        }
        swap(arr[min_i], arr[j]);
    }
}
void insertion_sort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
}
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
void sort()
{
    std::string input;
    int size;
    int *arr;
    while (1)
    {

        std::cout << "please chose a numebr\nor enter q to exit expresion convertor\n";
        std::cout << "1: bubble sort\n";
        std::cout << "2: selection sort\n";
        std::cout << "3: insertion sort \n";
        // std::cout << "4: postfix to prefix\n";
        // std::cout << "5: prefix to infix\n";
        // std::cout << "6: prefix to postfix\n";
        // std::cout << "7: show history\n";
        std::getline(std::cin, input);
        if (input == "q" || input == "exit")
        {
            if (std::system("clear"))
            {
                fprintf(stderr, "faild to clear \n");
            };
            break;
        }
        int a = std::stoi(input);
        std::cout << "please inter your expresion:\n";
        std::getline(std::cin, input);
        arr = get_arr(input, size);
        switch (a)
        {
        case 1:
            bubble_sort(arr, size);
            print(arr, size);
            back_to_menu();
            break;
        case 2:
            selection_sort(arr, size);
            print(arr, size);
            back_to_menu();
            break;
        case 3:
            insertion_sort(arr, size);
            print(arr, size);
            back_to_menu();

        default:
            std::cout << "invalid";
            std::cout << "\n";
        }
    }
}
static void back_to_menu()
{
    std::cout << "press enter to back to menu...";
    std::getchar();
    if (std::system("clear"))
    {
        fprintf(stderr, "faild to clear \n");
    };
}