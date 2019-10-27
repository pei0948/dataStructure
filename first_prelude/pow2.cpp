#include <iostream>
using namespace std;

inline long long sqr(long long a) {return a*a;}


long long pow2_1(int n)//O(n)
{
	long long pow=1;	
	while(n>0)
	{
		pow<<=1;
		n--;
	}
	return pow;
}

long long pow2_r(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{
		int sign=n & 1;
		n>>=1;

		if(sign)
		{
			return sqr(pow2_r(n))<<1;
		}
		else
		{
			return sqr(pow2_r(n));
		}

	}
}

int main(int argc, char **argv)
{
	cout<<pow2_1(6)<<endl;
	cout<<pow2_r(6)<<endl;
}
