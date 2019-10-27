#include <iostream>
using namespace std;

//small to big
void sort(int A[], int n)
{
	
	bool sorted=false;

	while(!sorted)
	{
		sorted=true;
		for(int i=0; i<n-1; i++)
		{
			if(A[i]>A[i+1])
			{
				swap(A[i], A[i+1]);
				sorted=false;
			}
		
		}
		
		n--;
	}
	
}

template <typename T>
void arrayPrint(T a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(int argc, char **argv)
{
	int A[]={0,3,4,6,2,1,7,8,4,5,2,4};
	arrayPrint(A,12);
	sort(A,12);
	arrayPrint(A,12);

}
