#pragma once
#include "MatrixBase.h"

class Matrix3D : public MatrixBase
{
public:
	static const unsigned size = 3;

	Matrix3D();
	int element(unsigned i, unsigned j) const
	{
		return matrix[i][j];
	}
	int& element(unsigned i, unsigned j)
	{
		return matrix[i][j];
	}
private:
	int matrix[size][size];
};