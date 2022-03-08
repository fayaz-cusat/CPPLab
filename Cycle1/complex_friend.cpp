#include <iostream>

class Complex
{
	float real, imag;
public:
	Complex(){};
	Complex(float x, float y){real=x;imag=y;}
	void set_val(float x, float y){real=x;imag=y;}
	friend Complex sum(const Complex& c1, const Complex &c2);
	void show(){std::cout << real << " + " << imag << "i\n";}
};

Complex sum(const Complex& c1, const Complex &c2)
{
	Complex c3;
	c3.set_val(c1.real + c2.real, c1.imag + c2.imag);
	return c3;
}

int main()
{
	Complex c1(1.5, 6.7);
	Complex c2(12.4, 5.6);
	Complex c3 = sum(c1, c2);
	c3.show();
}

