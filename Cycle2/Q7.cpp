#include <iostream>

class alpha
{
    int data;

public:
    alpha(int x)
    {
        data = x;
        std::cout << "alpha initialized with data = " << data << '\n';
    }

    void get_alpha()
    {
        std::cout << "alpha = " << data << '\n';
    }
};

class beta
{
    int data;

public:
    beta(int y)
    {
        data = y;
        std::cout << "beta initialized with data = " << data << '\n';
    }

    void get_beta()
    {
        std::cout << "beta = " << data << '\n';
    }
};

class gamma : public beta, public alpha
{
    int data;

public:
    gamma(int i, int j, int k) : alpha(i), beta(j)
    {
        data = k;
        std::cout << "gamma initialized with data = " << data << '\n';
    }

    void get_gamma()
    {
        std::cout << "gamma = " << data << '\n';
    }
};

int main()
{
    int a, b, c;
    std::cout << "Enter alpha, beta and gamma: ";
    std::cin >> a >> b >> c;
    std::cout << '\n';
    gamma g(a, b, c);
    std::cout << "\nCalling gamma member functions: \n";
    g.get_alpha();
    g.get_beta();
    g.get_gamma();
}
