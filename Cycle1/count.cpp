#include <iostream>

class Point
{
	static int count;
	int x, y;
public:
	Point(){count++;}
	Point(int a, int b){x = a; y = b; count++;}
	static int showcount(){std::cout << count << '\n'; return count;}
};

int Point::count = 0;

int main()
{
	int ch = 0;
	do
	{
		std::cout << "1.Create point\n2.END\n>>> ";
		std::cin >> ch;
		if (ch == 1)
		{
			int x, y;
			std::cout << "Enter coordinates of point: ";
			std::cin >> x;
			std::cin >> y;
			Point pt(x, y);
			std::cout << "Number of points created: "; pt.showcount();
		}
		else if (ch != 2)
		{
			std::cout << "Invalid choice!";
		}
	} while (ch != 2);
}
