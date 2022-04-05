#include <iostream>
#include <cstring>
#include <cmath>

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

    double length();

    bool operator==(const vector &vec)
    {
        if (size != vec.size)
            return false;

        for (int i = 0; i < size; i++)
            if (arr[i] != vec.arr[i])
                return false;
        return true;
    }

    bool operator!=(const vector &vec)
    {
        return !((*this) == vec);
    }

    bool operator>(vector &vec)
    {
        return length() > vec.length();
    }

    bool operator>=(vector &vec)
    {
        return length() >= vec.length();
    }

    bool operator<(vector &vec)
    {
        return length() < vec.length();
    }

    bool operator<=(vector &vec)
    {
        return length() <= vec.length();
    }

    void input()
    {
        std::cout << "Enter length of vector: ";
        std::cin >> size;
        std::cout << "Enter elements of vector: ";
        delete arr;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            std::cin >> arr[i];
        }
    }
};

double vector::length()
{
    double len = 0;
    for (int i = 0; i < size; i++)
        len += std::pow(arr[i], 2);

    return std::sqrt(len);
}

int main()
{
    int ch;
    bool res;
    vector v1, v2;
    v1.input();
    v2.input();
    std::cout << "Operators:\n";
    do
    {
        std::cout << "1. ==\t2. !=\n3. >\t4. >=\n5. <\t 6. <=\n7. END\n>>> ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            res = (v1 == v2);
            break;
        case 2:
            res = (v1 != v2);
            break;
        case 3:
            res = (v1 > v2);
            break;
        case 4:
            res = (v1 >= v2);
            break;
        case 5:
            res = (v1 < v2);
            break;
        case 6:
            res = (v1 <= v2);
            break;
        case 7:
            break;
		default:
			continue;
        }
		if (ch == 7)
			break;
        if (res == true)
            std::cout << "TRUE\n\n";
        else
            std::cout << "FALSE\n\n";
    } while (ch != 7);
}
