#include <iostream>

int main()
{
    long long input;
    long long output = 0;
    std::cin >> input ;
    if (input < 1) output = -1;
    else 
        for (int i = 1; i <= input; i++) 
            output += i;
    std::cout << output << std::endl;
    return 0;
}