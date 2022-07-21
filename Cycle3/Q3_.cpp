#include <iostream>

double div(double a, double b)
{
    if (b == 0)
        throw "Division by zero is not defined.";
    return a / b;
}

int main()
{
    double x, y, res;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    try
    {
        res = div(x, y);
        std::cout << x << " / " << y << " = " << res;
    }
    catch (const char *err)
    {
        std::cout << err << '\n';
    }
}
