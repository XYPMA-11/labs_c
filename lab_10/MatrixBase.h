#pragma once
#include <ostream>

class MatrixBase
{
protected:
	MatrixBase(unsigned int iSize) : m_size(iSize)
	{
	}
public:
	unsigned int size() const
	{
		return m_size;
	}

	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;
	void operator*=(int iMult);
	void operator+=(MatrixBase& iAdd);

	friend std::ostream& operator<< (std::ostream& out, const MatrixBase& matrix);

private:
	const unsigned int m_size;
};
