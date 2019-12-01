#include "BinTreePei.hpp"
#include "BinNodePei.hpp"

#include <iostream>
using namespace std;

template <typename T>
class Trav
{
				public:
				void operator() (T t)
				{
								cout<<t<<endl;
				}
};

int main(int argc, char **argv)
{
				BinTreePei<int> btp;
				btp.insertAsRoot(5);
				BinNodePeiPosi(int) bnpp=btp.root();
				btp.insertAsLc(bnpp, 6);
				btp.insertAsRc(bnpp, 7);

				BinTreePei<int>* btp2=new BinTreePei<int>();
				btp2->insertAsRoot(1);
				btp2->insertAsLc(btp2->root(), 2);
				btp2->insertAsRc(btp2->root(), 3);
				btp.attachAsLc(bnpp->rc, btp2);

				Trav<int> trav;
				btp.travLevel(trav);
				return 0;
}
