#include <iostream>
#include <string>
#include <cstring>


class String
{
    char *arr;
    int len;

public:
    String() {}
    String(int n)
    {
        len = n;
        arr = new char[n + 1];
    }
    String(char *str)
    {
        len = std::strlen(str);
        arr = new char[len + 1];
        for (int i = 0; i < len + 1; i++)
        {
            arr[i] = str[i];
        }
    }

    bool operator==(const String &str)
    {
        if (len != str.len)
            return false;
        for (int i = 0; i < len; i++)
        {
            if (arr[i] != str.arr[i])
                return false;
        }
        return true;
    }

    char *get_arr()
    {
        return arr;
    }

    friend String concat(const String &str1, const String &str2);
};

String concat(const String &str1, const String &str2)
{
    int len = str1.len + str2.len;
    String out(len);
    std::strcpy(out.arr, str1.arr);
    std::strcpy(out.arr + str1.len, str2.arr);
    return out;
}

int main()
{
	char input1[1024], input2[1024];
	std::cout << "Enter first string: ";
	std::cin.getline(input1, sizeof(input1));
	std::cout << "Enter second string: ";
	std::cin.getline(input2, sizeof(input2));
	
	String str1(input1);
	String str2(input2);

    if (str1 == str2)
		std::cout << "Strings are equal\n";
	else
		std::cout << "Strings are not equal\n";

    String str3 = concat(str1, str2);

    std::cout << "Concatenated string is " << str3.get_arr() << '\n';
}
