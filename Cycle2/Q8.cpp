#include <iostream>
#include <cmath>

class Shape
{
public:
    virtual float area() = 0;
    virtual void setup() = 0;
};

class Rectangle : public Shape
{
    float length, breadth;

public:
    void setup()
    {
        std::cout << "Enter length and breadth of rectangle: ";
        std::cin >> length >> breadth;
    }

    float area()
    {
        return length * breadth;
    }
};

class Square : public Rectangle
{
    float side;

public:
    void setup()
    {
        std::cout << "Enter side of square: ";
        std::cin >> side;
    }

    float area()
    {
        return side * side;
    }
};

class Ellipse : public Shape
{
    float a, b;

public:
    void setup()
    {
        std::cout << "Enter length of semi major axis: ";
        std::cin >> a;
        std::cout << "Enter length of semi minor axis: ";
        std::cin >> b;
    }

    float area()
    {
        return 2 * acos(0.0) * a * b;
    }
};

class Circle : public Ellipse
{
    float r;

public:
    void setup()
    {
        std::cout << "Enter radius of circle: ";
        std::cin >> r;
    }

    float area()
    {
        return 2 * acos(0.0) * r * r;
    }
};

int main()
{
    int ch;
    Shape *shape;
    do
    {
        std::cout << "1. Rectangle\n2. Square\n3. Ellipse\n4. Circle\n5. END\n>>> ";
        std::cin >> ch;
        switch (ch)
        {
        case 1:
            shape = new Rectangle;
            break;
        case 2:
            shape = new Square;
            break;
        case 3:
            shape = new Ellipse;
            break;
        case 4:
            shape = new Circle;
            break;
        case 5:
            break;
        default:
            continue;
        }
        if (ch != 5)
        {
            shape->setup();
            std::cout << "Area = " << shape->area() << "\n\n";
            delete shape;
        }
    } while (ch != 5);
}
