#include <iostream>
#include <math.h>

class Square
{
    int nsides = 4;
    int side;

public:
    int getside() { return side; }
    void setside()
    {
        std::cout << "Enter side: ";
        std::cin >> side;
    }
};

class Rectangle
{
    int nsides = 4;
    int lb[2];

public:
    int *getlb() { return lb; }
    void setlb()
    {
        std::cout << "Enter length: ";
        std::cin >> lb[0];
        std::cout << "Enter breadth: ";
        std::cin >> lb[1];
    }
};

class Triangle
{
    int nsides = 3;
    int sides[3];

public:
    int *getsides()
    {
        return sides;
    }
    void setsides()
    {
        std::cout << "Enter sides: ";
        int i = 0;
        do
        {
            std::cin >> sides[i];
            i++;
        } while (i < 3);
    }
};

class Pentagon
{
    int nsides = 5;
    int side;

public:
    int getside() { return side; }
    void setside()
    {
        std::cout << "Enter side: ";
        std::cin >> side;
    }
};

class Octagon
{
    int nsides = 8;
    int side;

public:
    int getside() { return side; }
    void setside()
    {
        std::cout << "Enter side: ";
        std::cin >> side;
    }
};

int area(Square s)
{
    int side = s.getside();
    return side * side;
}

int area(Rectangle r)
{
    int *lb = r.getlb();
    return lb[0] * lb[1];
}

int area(Triangle t)
{
    int *sides = t.getsides();
    float sp = (sides[0] + sides[1] + sides[2]) / 2;
    double ar = sqrt(sp * (sp - sides[0]) * (sp - sides[1]) * (sp - sides[2]));
    return ar;
}

double area(Pentagon p)
{
    int side = p.getside();
    double ar = 0.25 * sqrt(5 * (5 + 2 * sqrt(5))) * (side * side);
    return ar;
}

double area(Octagon o)
{
    int side = o.getside();
    double ar = 2 * (1 + sqrt(2)) * (side * side);
    return ar;
}

int main()
{
    Pentagon r1;
    r1.setside();
    std::cout << "Area = " << area(r1) << '\n';
}
