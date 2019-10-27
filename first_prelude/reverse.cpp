#include <iostream>
using namespace std;

void reverse1(int a[], int lo, int hi)
{
	if(lo<hi)
	{
		swap(a[lo],a[hi]);
		lo++;
		hi--;
		reverse1(a,lo,hi);
	}
}

void reverse3(int a[], int lo, int hi)
{
	while(lo<hi)
	{
		swap(a[lo],a[hi]);
		lo++;
		hi--;
	}
}

void reverse2(int a[], int lo, int hi)
{
	next: if(lo<hi)
	      {
		      swap(a[lo],a[hi]);
	     	      lo++;
	     	      hi--;
		      goto next;
	      }
}


int main(int argc, char **argv)
{
	int a[]={3,1,4,1,5,9,2,6};
	reverse3(a,0,7);
	for(int i=0;i<8;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

	
	return 0;
}
