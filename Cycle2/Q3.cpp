#include <iostream>
#include <string>

class vector
{
    int size;
    int *arr;

public:
    vector()
    {
        size = 0;
        arr = new int[0];
    }

    vector(int x)
    {
        size = x;
        arr = new int[size];
    }

    vector(int x, int *items)
    {
        size = x;
        arr = new int[size];
        std::memcpy(arr, items, sizeof(int) * size);
    }

    friend std::istream &operator>>(std::istream &is, vector &vec);
    friend std::ostream &operator<<(std::ostream &os, vector &vec);
    friend int operator*(vector &v1, vector &v2);
};

std::istream &operator>>(std::istream &is, vector &vec)
{
    is >> vec.size;
    for (int i = 0; i < vec.size; i++)
        is >> vec.arr[i];
    return is;
}

std::ostream &operator<<(std::ostream &os, vector &vec)
{
    os << '[';
    for (int i = 0; i < vec.size; i++)
        os << ' ' << vec.arr[i] << ' ';
    os << ']';
    os << '\n';
    return os;
}

int operator*(vector &v1, vector &v2)
{
    int dot = 0;
    if (v1.size != v2.size)
        throw "Cannot find dot product for vectors of different sizes!";

    for (int i = 0; i < v1.size; i++)
        dot += v1.arr[i] * v2.arr[i];

    return dot;
}

int main()
{
    vector v1, v2;
    std::cout << "Enter vector 1 (first entry should be length of vector): ";
    std::cin >> v1;
    std::cout << "Enter vector 2 (first entry should be length of vector): ";
    std::cin >> v2;
    std::cout << '\n';
    std::cout << "Vector 1 = " << v1 << '\n';
    std::cout << "Vector 2 = " << v2 << '\n';
    try
    {
        std::cout << "Dot product = " << v1 * v2 << '\n';
    }
    catch (char *msg)
    {
        std::cout << msg;
    }
}
