#include <iostream>
#include <cstring>

class list
{
	int len;
	int *code;
	float *price;
	int *quantity;

public:
	list();
	void add_item();
	void remove_item();
	void bill();
};

list::list()
{
	len = 10;
	code = new int[10];
	price = new float[10];
	quantity = new int[10];
	std::memset(code, -1, 10 * sizeof(int));
	std::memset(price, -1, 10 * sizeof(int));
	std::memset(quantity, -1, 10 * sizeof(int));
}

void list::add_item()
{
	int x, z, i;
	float y;
	std::cout << "Enter code: ";
	std::cin >> x;
	for (i = 0; i < len; i++)
	{
		if (code[i] == x)
		{
			std::cout << "Enter quantity: ";
			std::cin >> z;
			std::cout << '\n';
			quantity[i] += z;
			return;
		}
	}
	std::cout << "Enter price: ";
	std::cin >> y;
	std::cout << "Enter quantity: ";
	std::cin >> z;
	std::cout << '\n';
	for (i = 0; i < len; i++)
	{
		if (code[i] == -1)
		{
			code[i] = x; price[i] = y; quantity[i] = z;
			return;
		}
	}
	int *new_code = new int[len * 2];
	float *new_price = new float[len * 2];
	int *new_quantity = new int[len * 2];
	for (i = 0; i < len; i++)
		new_code[i] = code[i]; new_price[i] = price[i]; new_quantity[i] = quantity[i];
	new_code[len] = x;
	new_price[len] = y;
	new_quantity[len] = z;
	for (i = len + 1; i < len * 2; i++)
	{
		new_code[i] = -1;
		new_price[i] = -1;
		new_quantity[i] = -1;
	}
}

void list::remove_item()
{
	int x, ch, y, idx = -1;
	std::cout << "Enter code of item to remove: ";
	std::cin >> x;
	
	do
	{
		std::cout << "1.Remove all\n2.Remove specific number\n3.Cancel\n>>> ";
		std::cin >> ch;
		std::cout << '\n';


		for (int i = 0; i < len; i++)
			if (code[i] == x)
				idx = i;
		if (idx == -1)
		{
			std::cout << "No such item exists!\n\n";
			return;
		}
	
		if (ch == 1)
		{
			code[idx] = -1; price[idx] = -1; quantity[idx] = -1;
			break;
		}
		else if (ch == 2)
		{
			std::cout << "Enter number of items to remove: ";
			std::cin >> y;
			quantity[idx] -= y;
			if (quantity[idx] <= 0)
			{
				code[idx] = -1; price[idx] = -1; quantity[idx] = -1;
			}
			break;
		}
		else if (ch == 3)
		{
			break;
		}
		else
		{
			std::cout << "Invalid choice.\n";
		}
	} while (ch != 3);
}

void list::bill()
{
	float total = 0;
	std::cout << "Code\tPrice\tQuantity\n";
	std::cout << "----------------------------------------\n";
	for (int i = 0; i < len; i++)
	{
		if (code[i] != -1)
		{
			std::cout << code[i] << '\t' << price[i] << '\t' << quantity[i] << '\n';
			total += price[i] * quantity[i];
		}
	}
	std::cout << "----------------------------------------\n";
	std::cout << "Total: " << total << '\n';
	std::cout << "----------------------------------------\n";
	std::cout << "\n";
}

int main()
{
	int ch;
	list shopping;
	do
	{
		std::cout << "1.Add item\n2.Purchase\n3.Stock\n4.END\n>>> ";
		std::cin >> ch;
		std::cout << '\n';
		if (ch == 1)
		{
			shopping.add_item();
		}
		else if (ch == 2)
		{
			shopping.remove_item();
		}
		else if (ch == 3)
		{
			shopping.bill();
		}
		else if (ch == 4)
			break;
		else
			std::cout << "Invalid choice.\n";
	} while (ch != 4);
}

