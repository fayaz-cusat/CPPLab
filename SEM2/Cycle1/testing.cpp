#include <iostream>

int main()
{
    int *x = new int;
    int *y = x;
    std::cout << x << '\n';
    std::cout << y << '\n';

    y++;

    std::cout << x << '\n';
    std::cout << y << '\n';
}
