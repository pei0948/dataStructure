#include <iostream>
using namespace std;

long long fib1(int n)//O(2^n)
{
	return (n<2)?
		n:
		fib1(n-1)+fib1(n-2);
}

long long fib2(int n, long long &prev)//O(n)
{
	if(n==0)
	{
		prev=1;
		return 0;
	}
	else
	{
		long long prevPrev;
		prev=fib2(n-1,prevPrev);
		return prev+prevPrev;
	}
}

long long fib3_i(int n)//O(n)
{
	long long f=1,g=0;
	while(n>0)
	{
		g=f+g;
		f=g-f;
		n--;
	}
	return g;
}

int main(int argc, char **argv)
{
	long long a=5;
	cout<<fib1(a)<<endl;
	cout<<fib1(6)<<endl;
	cout<<fib2(6,a)<<endl;
	cout<<fib3_i(6)<<endl;
	return 0;
}
