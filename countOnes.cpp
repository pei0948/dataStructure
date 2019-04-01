#include <iostream>
using namespace std;

int countOnes(int n)
{
		int num=0;
		while(n!=0)
		{
				num=(n&1)?num+1:num;
				n>>=1;
		}
		return num;
}

int main(int argc,char** argv)
{
	cout<<countOnes(13)<<endl;
	return 0;
}
