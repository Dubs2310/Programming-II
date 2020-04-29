#include "stdafx.h"
#include<iostream>
#include "Matrix.h"
#include"Matrix.cpp"

void main()
{
	Matrix<double> A(3, 2);
	cout << "Enter the Wins and losses of each team in one year:\n";
	cin >> A;
	cout << "Matrix A:\n" << A;

	Matrix<double> B(3, 2);
	cout << "Enter the Wins and losses of each team in the next year:\n";
	cin >> B;
	cout << "Matrix B:\n" << B;

	Matrix<double> C(3, 2);
	cout << "Enter the Wins and losses of each team in three years:\n";
	cin >> C;
	cout << "Matrix C:\n" << C;

	Matrix<double> D;
	D = C - A - B;
	cout << "The wins and losses of each team in the third year is:\n";
	cout << "Matrix D:\n" << D;
}