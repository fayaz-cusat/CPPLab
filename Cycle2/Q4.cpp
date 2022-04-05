#include <iostream>

class matrix
{
    int ncols, nrows;
    int **p;

public:
    matrix(){nrows = 0; ncols = 0; p = NULL;};
    matrix(int x, int y)
    {
        nrows = x;
        ncols = y;
        p = new int *[nrows];
        for (int i = 0; i < nrows; i++)
        {
            p[i] = new int[ncols];
            for (int j = 0; j < ncols; j++)
                p[i][j] = 0;
        }
    }

    matrix operator+(matrix &M)
    {
        if (nrows != M.nrows || ncols != M.ncols)
            throw "Incompatible dimensions for matrix addition!";
        matrix res(nrows, ncols);
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                res.p[i][j] = p[i][j] + M.p[i][j];
        return res;
    }

    matrix operator*(matrix &M)
    {
        if (ncols != M.nrows)
            throw "Incompatible dimensions for matrix multiplication!";
        matrix res(nrows, M.ncols);
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < M.ncols; j++)
                for (int k = 0; k < ncols; k++)
                    res.p[i][j] += p[i][k] * M.p[k][j];
        return res;
    }
    void input();
    void show();
};

void matrix::show()
{
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
            std::cout << p[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

void matrix::input()
{
    std::cout << "Enter elements of matrix:\n";
    for (int i = 0; i < nrows; i++)
        for (int j = 0; j < ncols; j++)
            std::cin >> p[i][j];
}

int main()
{
    int ch, r, c;
    matrix res;
    std::cout << "Enter dims of first matrix: ";
    std::cin >> r >> c;
    matrix m1(r, c);
    m1.input();
    std::cout << "Enter dims of second matrix: ";
    std::cin >> r >> c;
    matrix m2(r, c);
    m2.input();
    do
    {
        std::cout << "1. Add\n2. Multiply\n3. END\n>>> ";
        std::cin >> ch;
        if (ch == 1)
        {
            try
            {
                res = m1 + m2;
                res.show();
            }
            catch (const char *msg)
            {
                std::cout << msg << "\n\n";
            }
        }
        else if (ch == 2)
        {
            try
            {
                res = m1 * m2;
                res.show();
            }
            catch (const char *msg)
            {
                std::cout << msg << "\n\n";
            }
        }
    } while (ch != 3);
}
