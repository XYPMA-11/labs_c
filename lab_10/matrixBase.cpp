#include "pch.h"
#include <iostream>
#include "MatrixBase.h"
#include <locale>

using namespace std;

std::ostream& operator<< (std::ostream& out, const MatrixBase& matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
	{
		for (int j = 0; j < matrix.m_size; j++)
		{
			out << matrix.element(i, j) << " ";
		}
		out << '\n';
	}
	out << '\n';
	return out;
}

void fillMatrix(MatrixBase matrix_1, MatrixBase matrix_2)
{
	for (int i = 0, value = 1; i < matrix_1.size(); i++)
	{
		for (int j = 0; j < matrix_1.size(); j++, value++)
		{
			matrix_1.element(i, j) = matrix_2.element(i, j) = value;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int multiplier = 3;

	Matrix2D m2a, m2b;
	Matrix3D m3a, m3b;

	// заполнение матриц
	fillMatrix(m2a, m2b);
	fillMatrix(m3a, m3b);

	cout << "Начальная матрица 2х2: "<< endl << m2a << endl;
	m2a *= multiplier;
	cout << "Умножение матрицы на " << multiplier << ": " << endl << m2a << endl;
	m2a += m2b;
	cout << "Сложение начальной и умноженной матрицы: " << endl << m2a << endl;

	cout << "Начальная матрица 3х3: " << endl << m3a << endl;
	m3a *= multiplier;
	cout << "Умножение матрицы на " << multiplier << ": " << endl << m3a << endl;
	m3a += m3b;
	cout << "Сложение начальной и умноженной матрицы: " << endl << m3a << endl;
	return 0;
}
