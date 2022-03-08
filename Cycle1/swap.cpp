#include <iostream>

class class_2;

class class_1
{
	int member = 2;
public:
	friend void swap(class_1 x, class_2 y);
	void show_member(){std::cout << "class_1 member: " << member << '\n';}
};

class class_2
{
	int member = 1;
public:
	friend void swap(class_1 x, class_2 y);
	void show_member(){std::cout << "class_2 member: " << member << '\n';}
};

void swap(class_1 x, class_2 y)
{
	int temp = x.member;
	x.member = y.member;
	y.member = temp;
	std::cout << "Swapped!\n";
}

int main()
{
	class_1 c1;
	class_2 c2;
	c1.show_member();
	c2.show_member();
	swap(c1, c2);
	c1.show_member();
	c2.show_member();
}



