#include <iostream>

class String:
{
    char *arr;
    int len;

    String(int n)
    {
        len = n;
        arr = new char[n];
    }
    int lenFromCharArray(char arr[])
    {
        int i;
        for (i = 0; arr[i] != '\0'; i++)
            ;
        return i;
    }

    char *copyArray(char src[], char dest[], int n)
    {
        for (int i = 0; i < n; dest[i] = src[i++])
            ;
        return dest;
    }

public:
    String()
    {
        len = 1;
        arr = new char[]{'\0'};
    }
    String(char arr[]) : String(arr, lenFromCharArray(arr)) {}
    String(char arr[], int n)
    {
        len = n;
        this->arr = new char[len];
        copyArray(arr, (this->arr), n);
    }

    bool operator==(const String &str)
    {
        if (len != str.len)
            return false;
        for (int i = 0; i < len; i++)
            if (arr[i] != str.arr[i])
                return false;
        return true;
    }

    int length()
    {
        return len;
    }

    String operator+(const String &str)
    {
        int outLen = len + str.len;
        String out = String(outLen);
        copyArray(arr, out.arr, len);
        copyArray(str.arr, out.arr + len, str.len);
        return out;
    }

    char *c_str()
    {
        return arr;
    }

    friend std::ostream &operator<<(std::ostream &os, String &str)
    {
        return os << str.c_str();
    }
};

int main()
{
    String s1 = String("Hello");
    String s2 = String(" World!");
    String s3 = s1 + s2;
    std::cout << s3;
    return 0;
}