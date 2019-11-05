//g++ VectorPei.cpp main.cpp -o main 一定要把main放在后面,否则会报链接(ld)错误
//./main
#include "VectorPei.hpp"
#include "stdlib.h"
#include <iostream>
using namespace std;

template <typename T>
void permute(VectorPei<T> &v)
{
	for(int i=v.size(); i>1; i--)
	{
		swap(v[i-1], v[rand()%i]);
	}
}

template <typename T>
void printVector(VectorPei<T> v)
{
	int len=v.size();
	for(int i=0; i<len; i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

template <typename T>
void add1(T &e)
{
				e=e+1;
}

template <typename T>
class Increase1//class换成struct也可,class一定要注明public,struct不用
{
				public:
				void operator()(T &e)
				{
					e++;
				}
};

int main(int argc, char **argv)
{
	int a[]={3,2,4,6,5,4,8,7,9};

	VectorPei<int> vp(a,0,9);
	printVector(vp);
	vp.sort(0,9);
	printVector(vp);

	return 0;
}
