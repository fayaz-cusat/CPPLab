#include <iostream>

template <class T>
class Vector
{
	int len;
	T *arr;

public:
	void get_len()
	{
		std::cout << "Enter length of vector: ";
		std::cin >> len;
		arr = new T[len];
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

	Vector operator+(Vector vec)
	{
		Vector<T> res;
		if (len != vec.len)
			throw "Invalid vector lengths for vector addition.";
		res.len = len;
		res.arr = new T[len];
		for (int i = 0; i < len; i++)
			res.arr[i] = arr[i] + vec.arr[i];
		return res;
	}
};

int main()
{
	int ch;
	do
	{
		std::cout << "Enter vector datatype:\n";
		std::cout << "1. int\n2. double\n3. END\n>>> ";
		std::cin >> ch;
		if (ch == 1)
		{
			Vector<int> vec1;
			vec1.get_len();
			vec1.get_data();
			std::cout << "Vector 1:\n";
			vec1.print();
			Vector<int> vec2;
			vec2.get_len();
			vec2.get_data();
			std::cout << "Vector 2:\n";
			vec2.print();
			try
			{
				Vector<int> vec3 = vec1 + vec2;
				std::cout << "SUM:\n";
				vec3.print();
			}
			catch (const char *err)
			{
				std::cout << err;
				return 0;
			}
		}
		else if (ch == 2)
		{
			Vector<double> vec1;
			vec1.get_len();
			vec1.get_data();
			std::cout << "Vector 1:\n";
			vec1.print();
			Vector<double> vec2;
			vec2.get_len();
			vec2.get_data();
			std::cout << "Vector 2:\n";
			vec2.print();
			try
			{
				Vector<double> vec3 = vec1 + vec2;
				std::cout << "SUM:\n";
				vec3.print();
			}
			catch (const char *err)
			{
				std::cout << err;
				return 0;
			}
		}
		else
			break;
	} while (ch != 3);
}
