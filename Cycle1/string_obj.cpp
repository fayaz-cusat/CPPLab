#include <iostream>

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
    String str1("Hello");
    String str2(" World!");
    String str3("Hello");

    std::cout << (str1 == str2) << '\n';
    std::cout << (str1 == str3) << '\n';

    String str4 = concat(str1, str2);

    std::cout << str4.get_arr() << '\n';
}
