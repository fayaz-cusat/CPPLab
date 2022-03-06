#include <iostream>

class Array
{
    int size;
    int *arr;

public:
    Array()
    {
        arr = NULL;
        size = 0;
    }
    Array(int n)
    {
        size = n;
        arr = new int[size];
        std::cout << "Constructor called.\n";
    }

    ~Array()
    {
        delete arr;
        std::cout << "Destructor called.\n";
    }
};

int main()
{
    Array arr1(10);
}
