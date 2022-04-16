#include <iostream>
#include <cstring>
#include <cmath>
#include <assert.h>
#include <exception>

class Matrix
{
    int *arr;
    int nrows = 0, ncols = 0;

    void init_empty(int rows, int cols)
    {
        nrows = rows;
        ncols = cols;
        arr = new int[nrows * ncols];
    }

    void init_zeros(int nrows, int ncols)
    {
        init_empty(nrows, ncols);
        memset(arr, 0, sizeof(int) * nrows * ncols);
    }

    void init_data(int nrows, int ncols, int *data)
    {
        init_empty(nrows, ncols);
        memcpy(arr, data, sizeof(int) * nrows * ncols);
    }

    void iadd(Matrix &m)
    {
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                set(i, j, get(i, j) + m.get(i, j));
    }

    void imul(Matrix &m)
    {
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                set(i, j, get(i, j) * m.get(i, j));
    }

    void isub(Matrix &m)
    {
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                set(i, j, get(i, j) - m.get(i, j));
    }

    void idiv(Matrix &m)
    {
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                set(i, j, get(i, j) / m.get(i, j));
    }

public:
    Matrix()
    {
        init_zeros(0, 0);
    }

    Matrix(int rows, int cols)
    {
        init_zeros(rows, cols);
    }

    Matrix(int rows, int cols, int *data)
    {
        init_data(rows, cols, data);
    }

    int get(int row, int col)
    {
        return arr[row * ncols + col];
    }

    void set(int row, int col, int val)
    {
        arr[row * ncols + col] = val;
    }

    void print_matrix()
    {
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
                std::cout << get(i, j) << ' ';
            std::cout << '\n';
        }
        std::cout << '\n';
    }

    Matrix matrix_add(Matrix &m)
    {
        if (!(m.nrows == nrows && m.ncols == ncols))
        {
            throw 0;
        }
        Matrix out(nrows, ncols, arr);
        out.iadd(m);
        return out;
    }

    Matrix matrix_sub(Matrix &m)
    {
        Matrix out(nrows, ncols, arr);
        out.isub(m);
        return out;
    }

    Matrix elemwise_mul(Matrix &m)
    {
        assert(m.nrows == nrows && m.ncols == ncols);
        Matrix out(nrows, ncols, arr);
        out.imul(m);
        return out;
    }

    Matrix elemwise_div(Matrix &m)
    {
        assert(m.nrows == nrows && m.ncols == ncols);
        Matrix out(nrows, ncols, arr);
        out.idiv(m);
        return out;
    }

    Matrix matrix_mult(const Matrix &m)
    {
        if (ncols != m.nrows)
        {
            throw 0;
        }
        Matrix out(nrows, m.ncols);
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < m.ncols; j++)
            {
                for (int k = 0; k < ncols; k++)
                {
                    out.arr[i * out.ncols + j] += arr[i * ncols + k] * m.arr[k * m.ncols + j];
                }
            }
        }

        return out;
    }

    Matrix matrix_transpose()
    {
        Matrix out(ncols, nrows);
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                out.arr[j * out.ncols + i] = arr[i * ncols + j];
            }
        }
        return out;
    }

    int matrix_determinant()
    {
        int det = 0;
        if (nrows != ncols)
        {
            throw 0;
        }
        if (nrows == 2)
        {
            det = arr[0] * arr[3] - arr[1] * arr[2];
            return det;
        }
        for (int j = 0; j < ncols; j++)
        {
            Matrix slice(nrows - 1, ncols - 1);
            int slice_i = 0, slice_j = 0;
            for (int i = 0; i < nrows; i++)
            {
                for (int k = 0; k < ncols; k++)
                {
                    if (i != 0 && k != j)
                    {
                        slice.set(slice_i, slice_j, get(i, k));
                        slice_j++;
                        if (slice_j == ncols - 1)
                        {
                            slice_j = 0;
                            slice_i++;
                        }
                    }
                }
            }
            det += std::pow(-1, j) * get(0, j) * slice.matrix_determinant();
        }
        return det;
    }
};

int main()
{
    int nrows, ncols, i, ch, ch2;
    std::cout << "Enter dimensions of matrix 1: ";
    std::cin >> nrows >> ncols;
    int *arr = new int[nrows * ncols];
    std::cout << "Enter rows of matrix 1:\n";
    for (i = 0; i < nrows * ncols; i++)
        std::cin >> arr[i];
    std::cout << '\n';
    Matrix m1(nrows, ncols, arr);
    std::cout << "Enter dimensions of matrix 2: ";
    std::cin >> nrows >> ncols;
    arr = new int[nrows * ncols];
    std::cout << "Enter rows of matrix 2:\n";
    for (i = 0; i < nrows * ncols; i++)
        std::cin >> arr[i];
    Matrix m2(nrows, ncols, arr);
    std::cout << '\n';

    do
    {
        std::cout << "1.ADD\n2.MULTIPLY\n3.TRANSPOSE\n4.DETERMINANT\n5.END\n>>> ";
        std::cin >> ch;
        std::cout << '\n';
        switch (ch)
        {
        case 1:
            std::cout << "SUM OF MATRICES\n";
            try
            {
                m1.matrix_add(m2).print_matrix();
            }
            catch (int x)
            {
                std::cout << "Matrices of different shapes cannot be added.\n";
            }
            break;
        case 2:
            std::cout << "PRODUCT OF MATRICES\n";
            try
            {
                m1.matrix_mult(m2).print_matrix();
            }
            catch (int x)
            {
                std::cout << "Incorrect shapes for matrix multiplication.\n";
            }
            break;
        case 3:
            std::cout << "1.Matrix 1\n2.Matrix 2\n>>> ";
            std::cin >> ch2;
            std::cout << '\n';
            if (ch2 == 1)
            {
                std::cout << "TRANSPOSE OF MATRIX 1\n";
                m1.matrix_transpose().print_matrix();
            }
            else if (ch2 == 2)
            {
                std::cout << "TRANSPOSE OF MATRIX 2\n";
                m2.matrix_transpose().print_matrix();
            }
            else
            {
                std::cout << "Invalid choice.\n";
            }
            break;
        case 4:
            std::cout << "1.Matrix 1\n2.Matrix 2\n>>> ";
            std::cin >> ch2;
            std::cout << '\n';
            if (ch2 == 1)
            {
                try
                {
                    std::cout << "DETERMINANT OF MATRIX 1 = " << m1.matrix_determinant() << "\n\n";
                }
                catch (int x)
                {
                    std::cout << "Determinant cannot be found for non square matrices!\n";
                }
            }
            else if (ch2 == 2)
            {
                try
                {
                    std::cout << "DETERMINANT OF MATRIX 2 = " << m2.matrix_determinant() << "\n\n";
                }
                catch (int x)
                {
                    std::cout << "?\nDeterminant cannot be found for non square matrices!\n";
                }
            }
            else
            {
                std::cout << "Invalid choice.\n";
            }
            break;
        case 5:
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (ch != 5);
}
