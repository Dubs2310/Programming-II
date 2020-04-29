#include "stdafx.h"
#include<iostream>
#include "Matrix.h"

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