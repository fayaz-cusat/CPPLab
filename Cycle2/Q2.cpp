#include <iostream>

class complex
{
    double real, imag;

public:
    complex(){};
    complex(double x, double y)
    {
        real = x;
        imag = y;
    }
    friend complex operator+(complex &c1, complex &c2);
    friend complex operator*(complex &c1, complex &c2);
    void show()
    {
        std::cout << real << (imag < 0 ? " - " : " + ") << (imag < 0 ? imag * -1 : imag) << "i\n";
    }
    void input()
    {
        std::cout << "Enter real part: ";
        std::cin >> real;
        std::cout << "Enter imaginary part: ";
        std::cin >> imag;
    }
};

complex operator+(complex &c1, complex &c2)
{
    complex res;
    res.real = c1.real + c2.real;
    res.imag = c1.imag + c2.imag;
    return res;
}

complex operator*(complex &c1, complex &c2)
{
    complex res;
    res.real = c1.real * c2.real - c1.imag * c2.imag;
    res.imag = c1.real * c2.imag + c2.real * c1.imag;
    return res;
}

int main()
{
    int ch;
    complex c1, c2, c3;
    std::cout << "COMPLEX 1\n";
    c1.input();
    std::cout << '\n';
    c1.show();
    std::cout << '\n';
    std::cout << "COMPLEX 2\n";
    c2.input();
    std::cout << '\n';
    c2.show();
    std::cout << '\n';
    do
    {
        std::cout << "1. ADD\n2. MULTIPLY\n3. END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
            c3 = c1 + c2;
        else if (ch == 2)
            c3 = c1 * c2;
        else
            break;
        c3.show();
        std::cout << '\n';
    } while (ch != 3);
}
