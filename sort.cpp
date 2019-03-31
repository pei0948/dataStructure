#include <iostream>
using namespace std;

void bubbleSort(float *A,int len)
{
		bool sorted=false;
		while(!sorted)
		{
				sorted=true;
				for(int i=1;i<len;i++)
				{
						if(A[i-1]>A[i])
						{
								swap(A[i-1],A[i]);
								sorted=false;
						}
				}
				len--;
		}
}

int main(int argc,char **argv)
{
	float A[]={5,6,2,3,4};
	bubbleSort(A,5);
	for(int i=0;i<5;i++)
	{
			cout<<A[i]<<endl;
	}
	return 0;
}
