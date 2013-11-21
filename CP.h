#ifndef CP_H_
#define CP_H_

#include <vector>
#include <iostream>
#include <exception>
using std::exception;
using std::vector;
using std::ostream;
class CartesianProduct {
public:
	/* the nested iterator class */
	class iterator {
	public:
		iterator(vector<vector<int> > *pData = NULL, int Position = -1)
			: mData(pData), mPosition(Position) 
		{}
		iterator(const iterator&);
		const iterator& operator=(const iterator&);
		iterator& operator++(void);
		bool operator!=(const iterator&);
		iterator operator++(int);
		iterator& operator--(void);
		iterator operator--(int);
		vector<int>& operator*(void);
		vector<int>* operator->(void);
		friend ostream& operator<<(ostream &, const vector<int>&);
		~iterator(){};
	private:
		vector<vector<int> > *mData;
		int mPosition;
		

	};
	CartesianProduct(const vector<vector<int> > &);
	~CartesianProduct(){};
	CartesianProduct(const CartesianProduct&);
	const CartesianProduct& operator=(CartesianProduct&);
	friend ostream& operator<<(ostream&, const CartesianProduct&);
	iterator begin(void);
	iterator end(void);
private:
	vector<vector<int> > mData;
	int mHeight;
	int mWidth;
	iterator mIterator;

};


#endif
