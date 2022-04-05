#include <iostream>
#include <cmath>

class Container
{
	public:
		virtual void get_dims() = 0;
		virtual double volume() = 0;		
};

class Box: public Container
{
	double length, breadth, height;
public:
	void get_dims();
	double volume();	
};

void Box::get_dims()
{
	std::cout << "Enter length of box: ";
	std::cin >> length;
	std::cout << "Enter breadth of box: ";
	std::cin >> breadth;
	std::cout << "Enter height of box: ";
	std::cin >> height;
}

double Box::volume()
{
	double vol = length * breadth * height;
	std::cout << "\nVolume of box = " << vol << '\n';
	return vol;
}

class Bottle: public Container
{
	double height, radius;
public:
	void get_dims();
	double volume();
};

void Bottle::get_dims()
{
	std::cout << "Enter radius of bottle: ";
	std::cin >> radius;	
	std::cout << "Enter height of bottle: ";
	std::cin >> height;
}

double Bottle::volume()
{
	double pi = std::acos(0.0) * 2;
	double vol = pi * radius * radius * height;
	std::cout << "\nVolume of bottle = " << vol << '\n';
	return vol;
}

int main()
{
	Container* container;
	int ch;
	do
	{
		std::cout << "1.Box\n2.Bottle\n3.END\n>>> ";
		std::cin >> ch;
		if (ch == 1)
		{
			container = new Box;
		}
		else if (ch == 2)
		{
			container = new Bottle;
		}
		else
			break;

		container->get_dims();
		container->volume();
	}	while (ch != 3);
}
