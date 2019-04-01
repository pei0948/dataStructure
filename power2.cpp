#include <iostream>
using namespace std;

long long power2_1(int n)
{
		long long valPow=1;
		while(n!=0)
		{
				valPow<<=1;
				n--;
		}
		return valPow;
}

long long power2_2(int n)
{
		if(n==0)
		{
				return 1;
		}
		else
		{
				return (n&1)?(power2_2(n>>1)*power2_2(n>>1))<<1:power2_2(n>>1)*power2_2(n>>1);	
		}
}

int main(int argc,char** argv)
{
	int n=36;
	cout<<power2_1(n)<<endl;
	cout<<power2_2(n)<<endl;
	return 0;
}
