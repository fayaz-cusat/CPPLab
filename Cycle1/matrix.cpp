#include <iostream>
#include <assert.h>

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
        assert(m.nrows == nrows && m.ncols == ncols);
        Matrix out(nrows, ncols, arr);
        out.iadd(m);
        return out;
    }

    Matrix matrix_sub(Matrix &m)
    {
        assert(m.nrows == nrows && m.ncols == ncols);
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
        assert(ncols == m.nrows);
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
        assert(nrows == ncols);
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
            std::cout << "Slice" << '\n';
            slice.print_matrix();
            det += std::pow(-1, j) * slice.matrix_determinant();
        }
        return det;
    }
};

int main()
{
    int vals1[4]{1, 2, 3, 4};
    int vals2[4]{1, 0, 0, 1};
    Matrix m1(2, 2, vals1);
    m1.print_matrix();
    Matrix m2(2, 2, vals2);
    m2.print_matrix();
    Matrix m3 = m1.matrix_mult(m2);
    m3.print_matrix();
    Matrix m4 = m3.matrix_transpose();
    m4.print_matrix();
    Matrix m5 = m3.matrix_add(m4);
    m5.print_matrix();
    int vals3[]{1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mt(3, 3, vals3);
    mt.print_matrix();
    std::cout << "determinant: " << mt.matrix_determinant() << '\n';
}
