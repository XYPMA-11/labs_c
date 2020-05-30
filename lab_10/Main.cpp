#include "Matrix2D.h"
#include "Matrix3D.h"
#include <locale>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int multiplier = 3;

	Matrix2D m2a, m2b;
	Matrix3D m3a, m3b;

	cout << "��������� ������� 2�2: " << endl << m2a << endl;
	m2a *= multiplier;
	cout << "��������� ������� �� " << multiplier << ": " << endl << m2a << endl;
	m2a += m2b;
	cout << "�������� ��������� � ���������� �������: " << endl << m2a << endl;

	cout << "��������� ������� 3�3: " << endl << m3a << endl;
	m3a *= multiplier;
	cout << "��������� ������� �� " << multiplier << ": " << endl << m3a << endl;
	m3a += m3b;
	cout << "�������� ��������� � ���������� �������: " << endl << m3a << endl;

	system("pause");
	return 0;
}