#pragma once


class MatrixBase
{
protected:
	MatrixBase(unsigned int iSize) : m_size(iSize)
	{
		array = new int* [iSize];
		for (int i = 0; i < m_size; i++) 
		{
			array[i] = new int[m_size];
			for (int j = 0; j < m_size; j++) 
			{
				array[i][j] = 0;
			}
		}
	}
public:
	unsigned int size() const
	{
		return m_size;
	}

	virtual int element(unsigned int i, unsigned int j) const
	{
		return array[i][j];
	}

	virtual int& element(unsigned int i, unsigned int j)
	{
		return array[i][j];
	}

	void operator*=(int iMult)
	{
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				element(i, j) *= iMult;
			}
		}
	}

	void operator+=(MatrixBase &iAdd)
	{
		for (int i = 0; i < m_size; i++)
		{
			for (int j = 0; j < m_size; j++)
			{
				element(i, j) += iAdd.element(i, j);
			}
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const MatrixBase& matrix);

private:
	const unsigned int m_size;
	int** array;
};

class Matrix2D : public MatrixBase
{
public:
	Matrix2D() : MatrixBase(2) {}
	~Matrix2D() {}
};

class Matrix3D : public MatrixBase
{
public:
	Matrix3D() : MatrixBase(3) {}
	~Matrix3D() {}
};

