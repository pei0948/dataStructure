#include "BST.hpp"

#define balance(x) (stature(x->lc)==stature(x->rc))
#define balFac(x) (stature(x->lc)-stature(x->rc))
#define avlBance(x) (balFac(x)>-2 && balFac(x)<2)

template <typename T>
class AVL: public BST<T>
{
				public:
								BinNodePeiPosi(T) insert(T const &e);
								bool remove(T const &e);
};

template <typename T>
BinNodePeiPosi(T) AVL<T>::insert(T const &e)
{
				BinNodePeiPosi(T) x=this->search(e);
				if(x)
								return x;
				BinNodePeiPosi(T) xx=new BinNodePei<T>(e, this->_hot);
				this->_size++;
				for(BinNodePeiPosi(T) g=this->_hot; g; g=g->parent)
				{
								if(!avlBance(g))
								{
												fromParentTo(g)=this->rotateAt(tallerChild(tallerChild(g)));
								}
								else
								{
												this->updateHeight(g);
								}
				}
				return xx;
}

template <typename T>
bool AVL<T>::remove(T const &e)
{
				BinNodePeiPosi(T) x=this->search(e);
				if(!x)
								return false;
				removeAt(x, this->_hot);
				for(BinNodePeiPosi(T) g=this->_hot; g; g=g->parent)
				{
								if(!avlBance(g))
								{
												cout<<g->data<<endl;
												g=fromParentTo(g)=this->rotateAt(tallerChild(tallerChild(g)));
								}
								this->updateHeight(g);
				}
				return true;
}
