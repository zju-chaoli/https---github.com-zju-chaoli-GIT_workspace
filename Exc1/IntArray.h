#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <cassert>
using namespace std;


class IntArray
{
public:
	
	explicit IntArray(int psize=m_defaultarraysize);
	IntArray(const IntArray& pb);
	IntArray(int *array,int arraysize);
	IntArray& operator=(const IntArray& pb);
	virtual ~IntArray();
	inline int size() const;
	virtual int max();
	virtual int min();
	virtual int getitem(int pos);
	virtual bool setitem(int pos,int value);
	virtual void sort();

	virtual bool operator==(const IntArray& pb) const;
	virtual bool operator!=(const IntArray& pb) const;
	virtual int& operator[](const int pos);
	virtual void print();
	
private:
	IntArray();		//default constructor is not allowed
	int m_size;
	int *m_p;
	static const int m_defaultarraysize=20;
};

int IntArray::size() const
{
	return this->m_size;
}

#endif