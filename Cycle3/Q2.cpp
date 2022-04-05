#include <iostream>

template<class T>
class Vector
{
	int len;
	T* arr;

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
			Vector<int> vec;
			vec.get_len();	
			vec.get_data();
			vec.print();
		}
		else if (ch == 2)
		{
			Vector<double> vec;
			vec.get_len();
			vec.get_data();
			vec.print();
		}
		else
			break;
	} while(ch != 3);
}
