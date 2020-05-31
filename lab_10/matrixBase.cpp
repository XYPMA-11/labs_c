
#include "MatrixBase.h"

void MatrixBase::operator*=(int iMult)
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			element(i, j) *= iMult;
		}
	}
}

void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (int i = 0; i < m_size; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			element(i, j) += iAdd.element(i, j);
		}
	}
}

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