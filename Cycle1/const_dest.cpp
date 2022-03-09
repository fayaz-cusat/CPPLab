#include <iostream>

class Vector
{
	static int num;
	int *arr;
	int len;
	int obj_num;
public:
	Vector(int n){len = n; arr = new int[n]; obj_num = ++num; std::cout << "Vector " << obj_num << " created!\n";}
	~Vector(){delete arr; std::cout << "Vector " << obj_num << " destructed!\n";}
	void set_vals();
};

int Vector::num = 0;

void Vector::set_vals()
{
	std::cout << "Enter elements of vector (seperated by space): ";
	for (int i = 0; i < len; i++)
	{
		std::cin >> arr[i];
	}
}

int main()
{
	int ch = 0;
	int N;
	do
	{
		std::cout << "1.Create vector\n2.END\n>>> ";
		std::cin >> ch;
		
		if (ch == 1)
		{
			std::cout << "Enter size of vector: ";
			std:: cin >> N;
			Vector v1(N);
			v1.set_vals();
		}
		else if (ch != 2)
		{
			std::cout << "Invalid choice!\n";
		}
	} while (ch != 2);
}

