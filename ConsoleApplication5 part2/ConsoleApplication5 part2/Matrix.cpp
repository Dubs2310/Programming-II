#include "stdafx.h"
#include<iostream>
#include "Matrix.h"

template <class T>
Matrix<T>::Matrix<T>(int r, int c)
{
	row = r;
	col = c;
	if (row < 0 || col < 0)
	{
		cout << "The row or column size cannot be negative.\n\n";
		exit(0);
	}
	p = new T*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new T[col];
}

template <class T>
Matrix<T>::~Matrix<T>()
{
	for (int i = 0; i < row; ++i)
		delete[] p[i];
}

template <class T>
Matrix<T>::Matrix<T>(const Matrix<T>& ob)
{
	row = ob.row;
	col = ob.col;
	
	p = new T*[row];
	for (int i = 0; i < row; ++i)
		p[i] = new T[col];

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			p[i][j] = ob.p[i][j];
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& ob)
{
	if (this != &ob) //Checking if we are assigning the same values to the same matrix (I'm comparing the address of the lhs to the address of rhs)
	{
		if (row != ob.row || col != ob.col)
		{
			for (int i = 0; i < ob.row; ++i)
				delete[] p[i];

			p = new T*[ob.row];
			for (int i = 0; i < ob.row; ++i)
				p[i] = new T[ob.col];

			row = ob.row;
			col = ob.col;
		}
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				p[i][j] = ob.p[i][j];
	}
	return *this;
}

template <class T>
bool operator==(const Matrix<T>& ob1, const Matrix<T>& ob2)
{
	if (ob1.row == ob2.row && ob1.col == ob2.col)
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

template <class T>
Matrix<T> operator+(const Matrix<T>& ob1, const Matrix<T>& ob2)
{
	if (ob1.row != ob2.row && ob1.col != ob2.col)
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

	Matrix<T> tmp(R, C);

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			tmp.p[i][j] = ob1.p[i][j] + ob2.p[i][j];

	return tmp;
}

template <class T>
Matrix<T> operator-(const Matrix<T>& ob1, const Matrix<T>& ob2)
{
	if (ob1.row != ob2.row && ob1.col != ob2.col)
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

	Matrix<T> tmp(R, C);

	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			tmp.p[i][j] = ob1.p[i][j] - ob2.p[i][j];

	return tmp;
}

template <class T>
ostream& operator<<(ostream& mycout, const Matrix<T>& ob)
{
	for (int i = 0; i < ob.row; ++i)
	{
		for (int j = 0; j < ob.col; ++j)
			mycout << ob.p[i][j] << '	';

		mycout << '\n';
	}
	return mycout;
}

template <class T>
istream& operator>>(istream& mycin, Matrix<T>& ob)
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

template <class T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& ob)
{
	if (row != ob.row && col != ob.col)
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

template <class T>
Matrix<T> Matrix<T>::operator-=(const Matrix<T>& ob)
{
	if (row != ob.row && col != ob.col)
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

template <class T>
T& Matrix<T>::operator()(int r, int c) const
{
	if (r < row && c < col)
		return p[r][c];
	else if (r >= row || c >= col)
	{
		cout << "The row or column index exceed the matrix row and column size.\n";
		exit(0);
	}
	else if (r < 0 || c < 0)
	{
		cout << "The row or column index cannot be negative.\n";
		exit(0);
	}
}

template <class T>
const T& Matrix<T>::operator()(int r, int c)
{
	if (r < row && c < col)
		return p[r][c];
	else if (r >= row || c >= col)
	{
		cout << "The row or column index exceed the matrix row and column size.\n";
		exit(0);
	}
	else if (r < 0 || c < 0)
	{
		cout << "The row or column index cannot be negative.\n";
		exit(0);
	}
}