#include <iostream>
#include <string>
#include <cstring>

class String
{
	char *arr;
	int len;
	
public:
	String(int n){len = n; arr = new char[n + 1];}
	String(char *input);
	String operator+(const String &str2);
	bool operator>(const String &str2);
	bool operator<(const String &str2);
	bool operator==(const String &str2);
	void display();
};

String::String(char *input)
{
	len = std::strlen(input);
	arr = new char[len + 1];
	std::strcpy(arr, input);
}

String String::operator+(const String &str2)
{
	String s3(len + str2.len);
	std::strcpy(s3.arr, arr);
	std::strcpy(s3.arr + len, str2.arr);
	return s3;
}

bool String::operator==(const String &str)
{
	if (len != str.len)
		return false;
	for (int i = 0; i < len; i++)
		if (arr[i] != str.arr[i])
			return false;
	return true;
}

bool String::operator>(const String &str)
	{
		if (len > str.len)
			return false;
		else
			return true;
	}
	
bool String::operator<(const String &str)
{
	if (len < str.len)
		return true;
	else
		return false;
}

void String::display()
{
	std::cout << arr << '\n';
}

int main()
{
	char input1[1024], input2[1024];
	std::cout << "Enter first string: ";
	std::cin.getline(input1, sizeof(input1));
	std::cout << "Enter second string: ";
	std::cin.getline(input2, sizeof(input2));
	String s1(input1), s2(input2);
	String s3 = s1 + s2;
	std::cout << "Concatenated: "; s3.display();
	if (s1 == s2)
		std::cout << "Strings are equal\n";
	else if (s1 > s2)
		std::cout << "String 1 is greater\n";
	else if (s2 < s1)
		std::cout << "String 2 is greater\n";
}

	
