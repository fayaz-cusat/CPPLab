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
	int ch = 0;
	Square s1;
	Rectangle r1;
	Triangle t1;
	Pentagon p1;
	Octagon o1;
	do
	{
		std::cout << "1.Square\n2.Rectangle\n3.Triangle\n4.Pentagon\n5.Octagon\n6.END\n>>> ";
		std::cin >> ch;
		switch (ch)
		{
			case 1:
				s1.setside();
				std::cout << "\nArea = " << area(s1) << "\n\n";
				break;

			case 2:
				r1.setlb();
				std::cout << "\nArea = " << area(r1) << "\n\n";
				break;

			case 3:
				t1.setsides();
				std::cout << "\nArea = " << area(t1) << "\n\n";
				break;

			case 4:
				p1.setside();
				std::cout << "\nArea = " << area(p1) << "\n\n";
				break;

			case 5:
				o1.setside();
				std::cout << "\nArea = " << area(o1) << "\n\n";
				break;

			case 6:
				break;

			default:
				std::cout << "\nInvalid choice!\n";
		}
	} while (ch != 6);
}
