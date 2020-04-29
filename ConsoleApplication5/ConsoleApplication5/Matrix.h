#include "stdafx.h"
#include<iostream>
using namespace std;
#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
	friend bool operator==(const Matrix& ob1, const Matrix& ob2);
	friend Matrix operator+(const Matrix& ob1, const Matrix& ob2);
	friend Matrix operator-(const Matrix& ob1, const Matrix& ob2);
	friend ostream& operator<<(ostream& mycout, const Matrix& ob);
	friend istream& operator>>(istream& mycin, Matrix& ob);

private:
	int row;
	int col;
	int **p; //Pointer to a pointer

public:
	Matrix(int r = 4, int c = 4);
	~Matrix();
	Matrix(const Matrix& ob);
	Matrix& operator=(const Matrix& ob);
	Matrix operator+=(const Matrix& ob);
	Matrix operator-=(const Matrix& ob);
	int& operator()(int r, int c) const;
	const int& operator()(int r, int c);
};
#endif // !MATRIX_H