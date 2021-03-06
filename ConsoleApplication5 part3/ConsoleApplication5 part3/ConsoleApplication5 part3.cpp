#include "stdafx.h"
#include<iostream>
using namespace std;

class Matrix
{
	friend bool operator==(const Matrix& ob1, const Matrix& ob2);
	friend Matrix operator+(const Matrix& ob1, const Matrix&ob2);
	friend Matrix operator-(const Matrix& ob1, const Matrix&ob2);
	friend ostream& operator<<(ostream& mycout, const Matrix& ob);
	friend istream& operator>>(istream& mycin, Matrix& ob);

private:
	int row;
	int col;
	int **p; //Pointer to a pointer

public:
	Matrix(int r = 4, int c = 4);
	~Matrix();
	Matrix(Matrix& ob);
	Matrix& operator=(const Matrix& ob);
	Matrix operator+=(const Matrix&ob);
	Matrix operator-=(const Matrix&ob);

	//STILL WORKING ON THE BONUS
	/*int& operator()(const Matrix& ob, int i, int j)
	{
	return ob.p[i][j];
	}

	const int& operator()(const Matrix& ob, int i, int j)
	{
	return ob.p[i][j];
	}*/
};

Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;

	p = new int*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new int[col];
}

Matrix::~Matrix()
{
	for (int i = 0; i < row; ++i)
		delete[] p[i];
}

Matrix::Matrix(Matrix& ob)
{
	row = ob.row;
	col = ob.col;

	p = new int*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new int[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			p[i][j] = ob.p[i][j];
}

Matrix& Matrix::operator=(const Matrix& ob)
{
	if (this != &ob) //Checking if we are assigning the same values to the same matrix (I'm comparing the address of the lhs to the address of rhs)
	{
		if (row != ob.row || col != ob.col)
		{
			for (int i = 0; i < ob.row; ++i)
				delete[] p[i];

			p = new int*[ob.row];
			for (int i = 0; i < ob.row; ++i)
				p[i] = new int[ob.col];

			row = ob.row;
			col = ob.col;
		}
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				p[i][j] = ob.p[i][j];
	}
	return *this;
}

bool operator==(const Matrix& ob1, const Matrix&ob2)
{
	if (ob1.row == ob2.row || ob1.col == ob2.col)
	{
		int R = ob1.row;
		int C = ob1.col;

		bool flag = true;

		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
			{
				if (ob1.p[i][j] != ob2.p[i][j])
					flag = false;
			}

		return flag;
	}
	return false;
}

Matrix operator+(const Matrix& ob1, const Matrix&ob2)
{
	if (ob1.row != ob2.row || ob1.col != ob2.col)
	{
		cout << "Matrix row and column sizes aren't the same\n";
		exit(0);
	}
	else if (ob1.row != ob2.row)
	{
		cout << "Matrix row sizes aren't the same\n";
		exit(0);
	}
	else if (ob1.col != ob2.col)
	{
		cout << "Matrix column sizes aren't the same\n";
		exit(0);
	}

	int R = ob1.row;
	int C = ob1.col;

	Matrix tmp(R, C);

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			tmp.p[i][j] = ob1.p[i][j] + ob2.p[i][j];

	return tmp;
}

Matrix operator-(const Matrix& ob1, const Matrix&ob2)
{
	if (ob1.row != ob2.row || ob1.col != ob2.col)
	{
		cout << "Matrix row and column sizes aren't the same\n";
		exit(0);
	}
	else if (ob1.row != ob2.row)
	{
		cout << "Matrix row sizes aren't the same\n";
		exit(0);
	}
	else if (ob1.col != ob2.col)
	{
		cout << "Matrix column sizes aren't the same\n";
		exit(0);
	}

	int R = ob1.row;
	int C = ob1.col;

	Matrix tmp(R, C);

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			tmp.p[i][j] = ob1.p[i][j] - ob2.p[i][j];

	return tmp;
}

Matrix Matrix::operator+=(const Matrix& ob)
{
	if (row != ob.row || col != ob.col)
	{
		cout << "Matrix row and column sizes aren't the same\n";
		exit(0);
	}
	else if (row != ob.row)
	{
		cout << "Matrix row sizes aren't the same\n";
		exit(0);
	}
	else if (col != ob.col)
	{
		cout << "Matrix column sizes aren't the same\n";
		exit(0);
	}

	row = ob.row;
	col = ob.col;


	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			p[i][j] += ob.p[i][j];

	return *this;
}

Matrix Matrix::operator-=(const Matrix& ob)
{
	if (row != ob.row || col != ob.col)
	{
		cout << "Matrix row and column sizes aren't the same\n";
		exit(0);
	}
	else if (row != ob.row)
	{
		cout << "Matrix row sizes aren't the same\n";
		exit(0);
	}
	else if (col != ob.col)
	{
		cout << "Matrix column sizes aren't the same\n";
		exit(0);
	}

	row = ob.row;
	col = ob.col;


	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			p[i][j] -= ob.p[i][j];

	return *this;
}

ostream& operator<<(ostream& mycout, const Matrix& ob)
{
	for (int i = 0; i < ob.row; ++i)
	{
		for (int j = 0; j < ob.col; ++j)
			mycout << ob.p[i][j] << '	';

		mycout << '\n';
	}

	return mycout;
}

istream& operator>>(istream& mycin, Matrix& ob)
{
	for (int i = 0; i < ob.row; ++i)
	{
		for (int j = 0; j < ob.col; ++j)
		{
			cout << "[" << i << "][" << j << "] = ";
			mycin >> ob.p[i][j];
		
		}
		cout << '\n';
	}
	return mycin;
}

void main()
{
	Matrix A(3, 2);
	cout << "Enter the Wins and losses of each team in one year:\n";
	cin >> A;
	cout << "Matrix A:\n" << A;

	Matrix B(3, 2);
	cout << "Enter the Wins and losses of each team in the next year:\n";
	cin >> B;
	cout << "Matrix B:\n" << B;

	Matrix C(3, 2);
	cout << "Enter the Wins and losses of each team in three years:\n";
	cin >> C;
	cout << "Matrix C:\n" << C;

	Matrix D;
	D = C - A - B;
	cout << "The wins and losses of each team in the third year is:\n";
	cout << "Matrix D:\n" << D;
}
