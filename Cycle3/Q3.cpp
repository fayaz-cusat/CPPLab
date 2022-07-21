#include <iostream>

class Vector
{
	int len;
	int *arr;

	Vector(int l)
	{
		len = l;
		arr = new int[len];
	}

public:
	Vector(){};
	void get_len()
	{
		std::cout << "Enter length of vector: ";
		std::cin >> len;
		if (len > 1000000)
			throw "Vector size too large!";
		arr = new int[len];
	}

	void get_data()
	{
		std::cout << "Enter vector data: ";
		for (int i = 0; i < len; i++)
			std::cin >> arr[i];
	}

	void print()
	{
		std::cout << "\nVector: ";
		std::cout << "[ ";
		for (int i = 0; i < len; i++)
			std::cout << arr[i] << ' ';
		std::cout << "]\n\n";
	}

	Vector operator+(Vector &v)
	{
		if (len != v.len)
			throw "Incompatible vector lengths for addition!\n";
		Vector res(len);
		for (int i = 0; i < len; i++)
			res.arr[i] = arr[i] + v.arr[i];
		return res;
	}
};

int main()
{
	char empty;
	Vector v1, v2, v3;
	std::cout << "Vector 1:\n";
	try
	{
		v1.get_len();
	}
	catch (const char *err)
	{
		std::cout << err << '\n';
		std::cin >> empty;
		v1.get_len();
	}
	v1.get_data();
	v1.print();
	std::cout << "Vector 2:\n";
	try
	{
		v2.get_len();
	}
	catch (const char *err)
	{
		std::cout << err << '\n';
		std::cin >> empty;
		v2.get_len();
	}
	v2.get_data();
	v2.print();
	try
	{
		v3 = v1 + v2;
		std::cout << "Sum:\n";
		v3.print();
	}
	catch (const char *err)
	{
		std::cout << err;
	}
}
