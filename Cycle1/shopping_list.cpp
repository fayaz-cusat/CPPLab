#include <iostream>
#include <cstring>

class ShoppingList
{
	int len_items;
	int* code_list;
	float* price_list;

public:
	ShoppingList(int len);
	void add_item(int code, float price);
	void remove_item(int code);
	float get_price(int code);
	float place_order();
};

ShoppingList::ShoppingList(int len)
{
	len_items = len;
	code_list = new int[len];
	price_list = new float[len];
	memset(code_list, -1, sizeof(float) * len);
	memset(code_list, -1, sizeof(int) * len);
}

void ShoppingList::add_item(int code, float price)
{
	if (code < 0 || price < 0)
	{
		std::cout << "Code and price cannot be negative.\n";
		return;
	}
	for (int i = 0; i < len_items; i++)
	{
		if (code_list[i] == -1)
		{
			code_list[i] =  code;
			price_list[i] = price;
			return;
		}
	}
	std::cout << "Shopping list has reached its maximum size.\n";
	return;
}

void ShoppingList::remove_item(int code)
{
	for (int i = 0; i < len_items; i++)
	{
		if (code_list[i] == code)
		{
			code_list[i] = -1;
			price_list[i] = -1;
			return;
		}
	}
	std::cout << "No such item!\n";
	return;
}

float ShoppingList::place_order()
{
	int ch = 0, code = 0, quantity = 0;
	float total = 0;
	do
	{
		std::cout << "1.Add item\t2.Exit";
		std::cin >> ch;
		if (ch == 1)
		{
			std::cout << "Enter item code: ";
			std::cin >> code;
			std::cout << "Enter quantity: ";
			std::cin >> quantity;
			total += code * quantity;
		}
		else if (ch == 2)
		{
			break;
		}
		else
			std::cout << "Invalid choice\n";
	} while (ch != 2);
}

int main(){}
