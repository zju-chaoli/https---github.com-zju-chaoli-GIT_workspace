#include "IntArray.h"


IntArray::IntArray(int psize)
{
	this->m_size=psize;
	this->m_p=new int[m_size];
	if(m_p==NULL)
	{
		cerr<<"can't create array for it"<<endl;
		exit(0);
	}
	int i=0;
	for(i=0;i<m_size;i++)
		m_p[i]=0;
}

IntArray::~IntArray()
{
	if(m_p!=NULL)
		delete[] m_p;
}
IntArray::IntArray(int *array,int arraysize)
{
	assert(array&&arraysize!=0);
	m_p=new int[arraysize];
	if(m_p==NULL)
	{
		cerr<<"can't allocate memory"<<endl;
		exit(0);
	}
	int i;
	for(i=0;i<arraysize;i++)
	{
		m_p[i]=array[i];
	}
}
IntArray::IntArray(const IntArray& pb)
{
	m_size=pb.m_size;
	m_p=new int[m_size];
	if(m_p==NULL){
		cerr<<"can't allocate the memory"<<endl;
		exit(0);
	}
	int i;
	for(i=0;i<m_size;i++)
		m_p[i]=*(pb.m_p+i);
}

IntArray& IntArray::operator=(const IntArray& pb)
{
	m_size=pb.m_size;
	m_p=new int[m_size];
	if(m_p==NULL){
		cerr<<"can't allocate the memory"<<endl;
		exit(0);
	}
	int i;
	for(i=0;i<m_size;i++)       //better solution using the memcopy
		m_p[i]=*(pb.m_p+i);
	//memcpy(m_p,pb.m_p,m_size*sizeof(int));
	return *this;
}

int& IntArray::operator[](const int pos)
{
	assert(m_p!=NULL&&pos<m_size&&pos>=0);
	return m_p[pos];
}

int IntArray::max()
{
	assert(m_p!=NULL&&m_size>=0);
	int i,temp=0;
	for(i=0;i<m_size;i++)
	{
		if(temp<m_p[i])
			temp=m_p[i];
	}
	return temp;
}
int IntArray::min()
{
	assert(m_p!=NULL&&m_size>=0);
	int i,temp=0;
	for(i=0;i<m_size;i++)
	{
		if(temp>m_p[i])
			temp=m_p[i];
	}
	return temp;
}

int IntArray::getitem(int pos)
{
	return operator[](pos);
}

bool IntArray::setitem(int pos, int value)
{
	assert(m_p!=NULL&&m_size>=0&&pos>=0&&pos<m_size);
	m_p[pos]=value;
	return true;
}

void IntArray::sort()
{
	int i,j;
	int temp;
	for(i=1;i<m_size;i++)
	{
		temp=m_p[i];
		for(j=i;j>=0;j--)
		{
			if(m_p[j-1]>temp)
			{
				m_p[j]=m_p[j-1];
			}
			else
				break;
		}
		m_p[j]=temp;
	}
}
bool IntArray::operator!=(const IntArray& pb) const
{
	int i;
	for(i=0;i<m_size;i++)
	{
		if(m_p[i]!=pb.m_p[i])
			return true;
	}
	return false;
}
bool IntArray::operator==(const IntArray& pb) const
{
	return !operator!=(pb);
}
void IntArray::print()
{
	int i;
	for(i=0;i<m_size;i++)
		cout<<"array["<<dec<<i<<"]="<<m_p[i];
	cout<<endl;
	return;
}