#include <iostream>
using namespace std;

#include "AVL.hpp"
#include "Splay.hpp"
#include <cstddef>

template <typename T>
class Visit
{
				public:
				void operator() (T data)
				{
								cout<<data<<endl;
				}
};

int main(int argc, char **argv)
{
				Splay<int> *btp=new Splay<int>();
				BinNodePeiPosi(int) root=btp->insertAsRoot(36);
				BinNodePeiPosi(int) rootLc=btp->insertAsLc(root, 27);
				BinNodePeiPosi(int) rootRc=btp->insertAsRc(root, 58);

				btp->insertAsLc(rootLc, 6);
				BinNodePeiPosi(int) rootRRc=btp->insertAsRc(rootRc, 69);
				BinNodePeiPosi(int) rootRLc=btp->insertAsLc(rootRc, 53);
				btp->insertAsLc(rootRLc, 46);

				btp->insert(37);

				cout<<btp->root()->data<<endl;
				return 0;
}
