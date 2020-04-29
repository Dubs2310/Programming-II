#include "stdafx.h"
#include<iostream>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H
template <class T>
class Matrix
{
	template <class T>
	friend bool operator==(const Matrix<T>& ob1, const Matrix <T>& ob2);
	template <class T>
	friend Matrix<T> operator+(const Matrix<T>& ob1, const Matrix <T>& ob2);
	template <class T>
	friend Matrix<T> operator-(const Matrix<T>& ob1, const Matrix <T>& ob2);
	template <class T>
	friend ostream& operator<<(ostream& mycout, const Matrix<T>& ob);
	template <class T>
	friend istream& operator>>(istream& mycin, Matrix<T>& ob);

private:
	int row;
	int col;
	T **p; //Pointer to a pointer

public:
	Matrix<T>(int r = 4, int c = 4);
	~Matrix<T>();
	Matrix<T>(const Matrix<T>& ob);
	Matrix<T>& operator=(const Matrix<T>& ob);
	Matrix<T> operator+=(const Matrix<T>& ob);
	Matrix<T> operator-=(const Matrix<T>& ob);
	T& operator()(int r, int c) const;
	const T& operator()(int r, int c);
};
#endif // !MATRIX_H






