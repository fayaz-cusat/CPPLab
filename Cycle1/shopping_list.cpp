#include <iostream>
#include <cstring>
#include <string>

class ShoppingList
{
	int len_items;
	int *code_list;
	float *price_list;

public:
	ShoppingList(int len);
	void add_item(int code, float price);
	void remove_item(int code);
	float get_price(int code);
	float place_order();
	void menu();
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
			code_list[i] = code;
			price_list[i] = price;
			return;
		}
	}
	std::cout << "\nShopping list has reached its maximum size!\n\n";
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

float ShoppingList::get_price(int code)
{
	for (int i = 0; i < len_items; i++)
	{
		if (code_list[i] == code)
		{
			return price_list[i];
		}
	}
}

float ShoppingList::place_order()
{
	int ch = 0, code = 0, quantity = 0;
	float total = 0;
	do
	{
		std::cout << "----------------------------------------\n";
		std::cout << "1.Add item\n2.Finish\n";
		std::cin >> ch;
		if (ch == 1)
		{
			std::cout << "Enter item code: ";
			std::cin >> code;
			std::cout << "Enter quantity: ";
			std::cin >> quantity;
			total += get_price(code) * quantity;
		}
		else if (ch == 2)
		{
			break;
		}
		else
			std::cout << "Invalid choice\n";
	} while (ch != 2);
	return total;
}

void ShoppingList::menu()
{
	int ch = 0, code = 0;
	float price = 0;
	do
	{
		std::cout << "1.Add item to inventory\n2.Remove item from inventory\n3.Place Order\n4.Exit\n>>> ";
		std::cin >> ch;
		if (ch == 1)
		{
			std::string price_s;
			std::cout << "Enter item code: ";
			std::cin >> code;
			std::cout << "Enter price: ";
			std::cin >> price_s;
			price = std::stof(price_s);
			add_item(code, price);
		}
		else if (ch == 2)
		{
			std::cout << "Enter item code: ";
			std::cin >> code;
			remove_item(code);
		}
		else if (ch == 3)
		{
			std::cout << "Total amount: " << place_order() << '\n';
		}
		else if (ch == 4)
		{
			break;
		}
		else
		{
			std::cout << "Invalid choice!\n";
		}
	} while (ch != 4);
}

int main()
{
	int N;
	std::cout << "Enter number of items in store: ";
	std::cin >> N;
	ShoppingList list(N);
	list.menu();
}
