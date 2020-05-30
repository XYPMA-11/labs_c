#include "Matrix3D.h"

Matrix3D::Matrix3D() : MatrixBase(size)
{
	for (int i = 0, value = 1; i < size; i++)
	{
		for (int j = 0; j < size; j++, value++)
		{
			matrix[i][j] = value;
		}
	}
}