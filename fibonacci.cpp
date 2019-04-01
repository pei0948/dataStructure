#include <iostream>
using namespace std;

long long fib1(int n)
{
		return (n<2)?
				n:
				fib1(n-1)+fib1(n-2);
}

long long fib2(int n,long long &preVal)
{
		if(n==0)
		{
				preVal=1;
				return n;
		}
		else
		{
				long long prePreVal;
				long long preVal=fib2(n-1,prePreVal);
				return preVal+prePreVal;
		}

}

long long fib3(int n)
{
	if(n<2)
	{
			return n;
	}
	else
	{
			long long f1=0;
			long long f2=1;
			while(n>0)
			{
				f2=f1+f2;
				f1=f2-f1;
				n--;
			}
			return f1;
	}
}

int main(int argc,char **argv)
{
		for(int i=0;i<6;i++)
		{
		//	long long preVal=0;
			cout<<fib3(i)<<endl;
		}
				return 0;
}
