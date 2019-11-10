#include "ListPei.hpp"

#include <iostream>
using namespace std;

template <typename T>
void printList(ListPei<T> &lp)
{
				int s=lp.size();
				for(int i=0; i<s; i++)
								cout<<lp[i]->data<<" ";
				cout<<endl;
}

int main(int argc, char **argv)
{
				int a[]={1,1,2,9,2,3,4};
				ListPei<int> lp(a, 6);

				printList(lp);
				lp.sort();
				printList(lp);
				return 0;

}
