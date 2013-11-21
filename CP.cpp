#include "CP.h"
typedef CartesianProduct::iterator CPI;

CartesianProduct::CartesianProduct(const vector<vector<int> > &Sets)
{
	int Size = Sets.size();
	if (Size == 0)
		throw exception();
	mWidth = Size;
	mHeight = 1;
	for (int i = 0; i < Size; i++) {
		mHeight *= Sets[i].size();
		if (mHeight == 0)
			throw exception();
	}
	/* generate the cartesian product */
	mData.resize(mHeight);

	for (int i = 0; i < mHeight; i++) {
		int j = 1;
		mData[i].resize(mWidth);
		for (int k = 0; k < mWidth; k++) {
			const int Len = Sets[k].size();
			mData[i][k] = Sets[k][i / j % Len];
			j *= Len;
		}
	}
}

CartesianProduct::CartesianProduct(const CartesianProduct& CP) : mData(CP.mData),
						mIterator(CP.mIterator),
						mHeight(CP.mHeight),
						mWidth(CP.mWidth)
{
}

CPI CartesianProduct::begin()
{
	CPI mBegin(&mData, 0);
	return mBegin;
}

CPI CartesianProduct::end()
{
	iterator mEnd(NULL, mHeight);
	return mEnd;
}
ostream& operator<<(ostream& os, const CartesianProduct& X)
{
	for (int i = 0; i < X.mHeight; i++) {
		for (int j = 0; j < X.mWidth; j++)
			os << X.mData[i][j] << " ";
		os << std::endl;
	}
	return os;
}

CPI::iterator(const iterator& other) : mData(other.mData), 
					mPosition(other.mPosition)
{
}

const CPI& CPI::operator=(const iterator& other)
{
	mPosition = other.mPosition;
	mData = other.mData;
}
CPI& CPI::operator++(void)
{
	mPosition++;
	return (*this);
}
CPI CPI::operator++(int)
{
	iterator temp(*this);
	mPosition++;
	return temp;
}

CPI& CPI::operator--(void)
{
	mPosition--;
	return (*this);
}

CPI CPI::operator--(int)
{
	iterator temp(*this);
	mPosition--;
	return temp;
}

vector<int>& CPI::operator*()
{
	return (*mData)[(mPosition)];
}

vector<int>* CPI::operator->()
{
	return &((*mData).at(mPosition));

}

bool CPI::operator!=(const iterator& other)
{
	if (mPosition != other.mPosition)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const vector<int>& X)
{
	const vector<int>& vec = X;
	int Size = vec.size();
	for (int i = 0; i < Size; i++)
		os << vec[i] << " ";
	return os;
}


