#include <iostream>

int count = 0;

class Matrix
{
	int **p;
	int nrows, ncols;
	int id;

public:
	Matrix(){id = ++count; std::cout << "Matrix " << id << "created!.\n";};
	Matrix(int, int);
	~Matrix();
	void alloc_matrix(int, int);
	void init_matrix();
	void print_matrix();
};

Matrix::Matrix(int x, int y)
{
	nrows = x; ncols = y;
	alloc_matrix(x, y);
	init_matrix();
	id = ++count;
	std::cout << "Matrix " << id << " created!\n\n";
}

void Matrix::alloc_matrix(int x, int y)
{
	p = new int*[nrows];

	for (int i = 0; i < nrows; i++)
		p[i] = new int[ncols];
}

void Matrix::init_matrix()
{
	std::cout << "Enter elements of matrix: \n";
	for (int i = 0; i < nrows; i++)
		for (int j = 0; j < ncols; j++)
			std::cin >> p[i][j];
	std::cout << '\n';
}

Matrix::~Matrix()
{
	for (int i = 0; i < nrows; i++)
		delete[] p[i];
	delete[] p;
	std::cout << "Matrix " << id << " deleted!\n\n";
}

void Matrix::print_matrix()
{
	for (int i = 0; i < nrows; i++)
	{
		for (int  j = 0; j < ncols; j++)
			std::cout << p[i][j] << ' ';
		std::cout << '\n';
	}
}

int main()
{
	int ch = 0, ch2 = 0, nrows, ncols;
	Matrix *mtx;
	do
	{
		std::cout << "\n1.Create Matrix\n2.End\n>>> ";
		std::cin >> ch;
		std::cout << '\n';
		if (ch == 1)
		{
			std::cout << "Enter shape of matrix: ";
			std::cin >> nrows >> ncols;
			mtx = new Matrix(nrows, ncols);
			do
			{
				std::cout << "1.Show matrix\n2.Release matrix\n>>> ";
				std::cin >> ch2;
				std::cout << '\n';
				if (ch2 == 1)
					mtx->print_matrix();
				else
					delete mtx;
			} while (ch2 == 1);
		}
	} while (ch != 2);
}

