#include <iostream>
using namespace std;

void reverse1(int *A,int begin,int end)
{
		while(end>begin)
		{
				swap(A[begin],A[end]);
				begin++;
				end--;
		}
}

void reverse2(int *A,int begin,int end)
{
		if(end>begin)
		{
				swap(A[begin],A[end]);

				begin++;
				end--;
				reverse2(A,begin,end);
				
		}
}

void reverse3(int *A,int begin,int end)
{
	next:
		if(end>begin)
		{
				swap(A[begin],A[end]);
				begin++;
				end--;
				goto next;
		}

}

int main(int argc,char **argv)
{
		int A[]={1,2,3,4};
		reverse3(A,0,3);

		for(int i=0;i<4;i++)
		{
				cout<<A[i]<<endl;
		}

		return 0;
}
