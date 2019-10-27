#include <iostream>
using namespace std;

int countOnes1(int a)//O(loga)
{
	int numOnes=0;
	while(a>0)
	{
		if(a & 1)
		{
			numOnes++;
		}
		a>>=1;
	}
	return numOnes;
}

int main(int argc, char **argv)
{
	int a=441;
	cout<<countOnes1(a)<<endl;
	return 0;
}
