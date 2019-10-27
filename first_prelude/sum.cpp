#include <iostream>
using namespace std;

template <typename T>
T sumT_i(T a[], int n)//O(n)
{
	T sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	return sum;
}

template <typename T>//O(n)
T sumT_r(T a[], int n)
{
	if(n>0)
	{
		return sumT_r(a,n-1)+a[n-1];
	}
	else
	{
		return 0;
	}
}

template <typename T>
T sumT_r2(T a[], int lo, int hi)//O(logn)
{
	if(lo==hi)
	{
		return a[lo];
	}
	int mi=(lo+hi)>>1;
	return sumT_r2(a,lo,mi)+sumT_r2(a,mi+1,hi);
}

int main(int argc, char **argv)
{
	int a[]={6,8,10,11};
	int sum1=sumT_i(a,4);
	int sum2=sumT_r(a,4);
	int sum3=sumT_r2(a,0,3);
	cout<<sum1<<endl;
	cout<<sum2<<endl;
	cout<<sum3<<endl;
	return 0;
}
