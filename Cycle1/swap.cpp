#include <iostream>

class class_2;

class class_1
{
	int member;
public:
	friend void swap(class_1 &x, class_2 &y);
	void show_member(){std::cout << "class_1 member: " << member << '\n';}
	void get_member(){std::cout << "Enter class_1 member: "; std::cin >> member;}
};

class class_2
{
	int member;
public:
	friend void swap(class_1 &x, class_2 &y);
	void show_member(){std::cout << "class_2 member: " << member << '\n';}
	void get_member(){std::cout << "Enter class_2 member: "; std::cin >> member;}
};

void swap(class_1 &x, class_2 &y)
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
	c1.get_member();
	c2.get_member();
	c1.show_member();
	c2.show_member();
	swap(c1, c2);
	c1.show_member();
	c2.show_member();
}



