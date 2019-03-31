#include <iostream>
using namespace std;

double sumD1(double *A,int n)
{
		double valSum=0; 
		for(int i=0;i<n;i++)
		{
				valSum+=A[i];
		}
		return valSum;
}

double sumD2(double *A,int n)
{
		if(n==0)
		{
				return 0;
		}
		else
		{
				return sumD2(A,n-1)+A[n-1];
		}
}

double sumD3(double *A,int begin,int end)
{
	if(begin==end)
	{
			return A[begin];
	}
	else
	{
			int mi=(begin+end)/2;
			return sumD3(A,begin,mi)+sumD3(A,mi+1,end);
	}
}

int main(int argc,char **argv)
{
	double A[]={1,2,3,4};
	cout<<sumD2(A,4)<<endl;
	cout<<sumD3(A,0,3)<<endl;
}
