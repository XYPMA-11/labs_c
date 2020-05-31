#pragma once
#include "MatrixBase.h"

class Matrix2D : public MatrixBase
{
public:
	static const unsigned size = 2;

	Matrix2D();
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