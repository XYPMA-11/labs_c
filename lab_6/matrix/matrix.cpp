#include "pch.h"
#include <iostream>
#include <ctime>
#include <locale>

//int array[3][3];

class Matrix3x3
{
public:
	int Element(const int i, const int j) const
	{
		return array[i][j];
	}

	void setElement(const int i, const int j, const int value)
	{
		array[i][j] = value;
	}

	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				array[i][j] = rand() % (maxVal * 2) + minVal;
	}

	int sumPrincipalDiag() const
	{
		return array[0][0] + array[1][1] + array[2][2];
	}

	int sumSecondaryDiag() const
	{
		return array[0][2] + array[1][1] + array[2][0];
	}

	int productPrincipalDiag() const
	{
		return array[0][0] * array[1][1] * array[2][2];
	}

	int productSecondaryDiag() const
	{
		return array[0][2] * array[1][1] * array[2][0];
	}

	int sumRow(const int iRow) const
	{
		return array[iRow][0] + array[iRow][1] + array[iRow][2];
	}

	int minColumn(const int iCol) const
	{
		int min = 11;
		for (int i = 0; i < 3; i++)
		{
			if (array[i][iCol] < min)
			{
				min = array[i][iCol];
			}
		}
		return min;
	}

	int maxColumn(const int iCol) const
	{
		int max = -11;
		for (int i = 0; i < 3; i++)
		{
			if (array[i][iCol] > max)
			{
				max = array[i][iCol];
			}
		}
		return max;
	}

	void printArray()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++) 
			{
				std::cout << array[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}

private:
	int array[3][3];
};

class MatrixXnX
{
public:
	MatrixXnX(const int iDim)
	{
		this->size = iDim;
		array = new int*[iDim];
		for (int i = 0; i < iDim; i++) {
			array[i] = new int[size];
			for (int j = 0; j < iDim; j++) {
				array[i][j] = 0;
			}
		}
	};


	int Element(const int i, const int j) const
	{
		return array[i][j];
	}

	void setElement(const int i, const int j, const int value)
	{
		array[i][j] = value;
	}

	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				array[i][j] = rand() % (maxVal * 2) + minVal;
	}

	int sumPrincipalDiag() const
	{
		int result = 0;
		for (int i = 0; i < size; i++)
		{
			result += array[i][i];
		}
		return result;
	}

	int sumSecondaryDiag() const
	{
		int result = 0;
		for (int i = 0; i < size; i++)
		{
			result += array[i][size - 1 - i];
		}
		return result;
	}

	int productPrincipalDiag() const
	{
		int result = 1;
		for (int i = 0; i < size; i++)
		{
			result *= array[i][i];
		}
		return result;
	}

	int productSecondaryDiag() const
	{
		int result = 1;
		for (int i = 0; i < size; i++)
		{
			result *= array[i][size - 1 - i];
		}
		return result;
	}

	int sumRow(const int iRow) const
	{
		int result = 0;
		for (int i = 0; i < size; i++) 
		{
			result += array[iRow][i];
		}
		return result;
	}

	int minColumn(const int iCol) const
	{
		int min = 11;
		for (int i = 0; i < size; i++)
		{
			if (min > array[i][iCol]) 
			{
				min = array[i][iCol];
			}
		}
		return min;
	}

	int maxColumn(const int iCol) const
	{
		int max = -11;
		for (int i = 0; i < size; i++) 
		{
			if (max < array[i][iCol]) 
			{
				max = array[i][iCol];
			}
		}
		return max;
	}

	void printArray()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++) {
				std:: cout << array[i][j] << ' ';
			}
			std:: cout << std::endl;
		}
	}

private:
	int **array;
	int size;
};

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	std::cout << "Статическая матрица:" << std::endl;
	Matrix3x3 matrix3;
	matrix3.fillRandomElements(-10, 10);
	matrix3.printArray();

	std::cout << "Элемент (2,2): " << matrix3.Element(1, 1) << "\n"
		<< "Сумма элементов главной диагонали: " << matrix3.sumPrincipalDiag() << "\n"
		<< "Сумма элементов побочной диагонали: " << matrix3.sumSecondaryDiag() << "\n"
		<< "Произведение элементов главной диагонали: " << matrix3.productPrincipalDiag() << "\n"
		<< "Произведение элементов побочной диагонали: " << matrix3.productSecondaryDiag() << "\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Сумма " << i + 1 << " строки: " << matrix3.sumRow(i) << "\n"
			<< "Максимальый элемент " << i + 1 << " столбца: " << matrix3.maxColumn(i) << "\n"
			<< "Минимальный элемент " << i + 1 << " столбца: " << matrix3.minColumn(i) << "\n";
	}

	std::cout << "\nДинамическая матрица:" << std::endl;
	int size = 4;
	MatrixXnX matrixX(size);
	matrixX.fillRandomElements(-10, 10);
	matrixX.printArray();

	std::cout << "Элемент (2,2): " << matrixX.Element(1, 1) << "\n"
		<< "Сумма элементов главной диагонали: " << matrixX.sumPrincipalDiag() << "\n"
		<< "Сумма элементов побочной диагонали: " << matrixX.sumSecondaryDiag() << "\n"
		<< "Произведение элементов главной диагонали: " << matrixX.productPrincipalDiag() << "\n"
		<< "Произведение элементов побочной диагонали: " << matrixX.productSecondaryDiag() << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "Сумма " << i + 1 << " строки: " << matrixX.sumRow(i) << "\n"
			<< "Максимальый элемент " << i + 1 << " столбца: " << matrixX.maxColumn(i) << "\n"
			<< "Минимальный элемент " << i + 1 << " столбца: " << matrixX.minColumn(i) << "\n";
	}
}