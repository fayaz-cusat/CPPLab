#include <iostream>

class Complex
{
	float x, y;
	
public:
	Complex(){};
	Complex(float a);
	Complex(float a, float b);
	void show(){std::cout << x << (y > 0 ? " + " : " - ") << (y > 0 ? y : (-1 * y)) << "i\n";}
	Complex operator+(const Complex &c2);
	void set_val(float a, float b){x = a; y = b;}
};

Complex::Complex(float a)
{
	x = a;
	y = a;
}

Complex::Complex(float a, float b)
{
	x = a;
	y = b;
}

Complex Complex::operator+(const Complex &c2)
{
	Complex res(x + c2.x, y + c2.y);
	return res;	
}

int main()
{
	float x, y;
	Complex c1;
	std::cout << "Enter values for uninitialized complex 1: ";
	std::cin >> x >> y;
	c1.set_val(x, y);
	c1.show();
	std::cout << "Enter single value for complex 2: ";
	std::cin >> x;
	Complex c2(x);
	c2.show();
	std::cout << "Enter values for complex 3: ";
	std::cin >> x >> y;
	Complex c3(x, y);
	c3.show();
	std::cout << "complex 1 + complex 2 = ";
	(c1 + c2).show(); 
}
