#include <iostream>

class Shape
{
public:
    virtual float area() { return 0; }
    virtual float perimeter() { return 0; }
};

class Rectangle : public Shape
{
    int l, b;

public:
    Rectangle(float x, float y) : l(x), b(y){};
    // float area()
    // {
    //     return l * b;
    // }
    float perimeter()
    {
        return 2 * (l + b);
    }
};

int main()
{
    Shape *shape;
    shape = new Rectangle(5.5, 6.2);
    std::cout << shape->area() << '\n';
    std::cout << shape->perimeter() << '\n';
}
