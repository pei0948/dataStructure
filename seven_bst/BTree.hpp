#ifndef BTREE
#define BTREE

#include <cstddef>

#include "../second_vector/VectorPei.hpp"

#include <iostream>
using namespace std;

#define BTNodePosi(T) BTNode<T>*

template <typename T>
struct BTNode
{
				BTNodePosi(T) parent;
				VectorPei<T> key;
				VectorPei<BTNodePosi(T)> child;

			  BTNode()
				{
								parent=NULL;
								key.insert(0, NULL);
				}

				BTNode(T e, BTNodePosi(T) lc=NULL, BTNodePosi(T) rc=NULL)
				{
								parent=NULL;
								key.insert(0, e);
								child.insert(0, lc);
								child.insert(1, rc);

								if(lc)
												lc->parent=this;
								if(rc)
												rc->parent=this;
				}
};

template <typename T>
class BTree
{
				protected:
								int _size;
								int _order;
								BTNodePosi(T) _root;
								BTNodePosi(T) _hot;
								void solveOverflow(BTNodePosi(T));
								void solveUnderflow(BTNodePosi(T));

				public:
								BTree(int order=4)
								{
												_order=order;
												_size=0;
												_root=new BTNode<T>();
								}
								~BTree()
								{
												if(_root)
																delete _root;
								}
								int const getOrder()
								{
												return _order;
								}
								int const getSize()
								{
												return _size;
								}

								int incSize(int s)
								{
												_size=_size+s;
												return _size;
								}

								BTNodePosi(T)& getRoot()
								{
												return _root;
								}

								bool empty()
								{
												return (!_root);
								}

								BTNodePosi(T) search(T const &e);
								bool insert(T const &e);
								bool remove(T const &e);

};

template <typename T>
BTNodePosi(T) BTree<T>::search(T const &e)
{
				BTNodePosi(T) btnp=_root;
				_hot=NULL;
				while(btnp)
				{
								Rank r=btnp->key.search(e);
								if(e==btnp->key[r])
								{
												return btnp;
								}
								else
								{
												_hot=btnp;
												btnp=btnp->child[r+1];
								}
				}
				return NULL;
}

template <typename T>
bool BTree<T>::insert(T const &e)
{
				BTNodePosi(T) btnp=search(e);
				if(btnp)
								return false;
				Rank r=_hot->key.search(e);
				_hot->key.insert(r+1, e);
				_hot->child.insert(r+2, NULL);

				_size++;
				solveOverflow(_hot);
				return true;
}

template <typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) btnp)
{
				if(btnp->child.size()<=_order)
								return;

				BTNodePosi(T) u=new BTNode<T>();
				Rank m=_order/2;
				for(int i=0; i<_order-m-1; i++)
				{
								u->key.insert(i, btnp->key.remove(m+1));
								u->child.insert(i, btnp->child.remove(m+1));
				}
				u->child.insert(_order-m-1, btnp->child.remove(m+1));
				for(int i=0; i<_order-m; i++)
				{
								if(u->child[i])
								{
												u->child[i]->parent=u;
								}
				}
				BTNodePosi(T) p=btnp->parent;
				if(!p)
				{
								p=new BTNode<T>(p->key.remove(m));
								_root=p;
								p->child.insert(0, btnp);
								btnp->parent=p;
								p->child.insert(1, u);
								u->parent=p;
				}
				else
				{
								Rank r=p->key.search(p->key[m]);
								p->key.insert(r+1, btnp->key.remove(m));
								p->child.insert(r+2, u);
								u->parent=p;
				}
				solveOverflow(p);

}

template <typename T>
bool BTree<T>::remove(T const &e)
{
				BTNodePosi(T) btnp=search(e);
				if(!btnp)
								return false;
				Rank r=btnp->key.search(e);
				
				BTNodePosi(T) btnpC=btnp->child[r+1];
				if(btnpC)
				{
								while(btnpC->child[0])
								{
												btnpC=btnpC->child[0];
								}
								btnp->key[r]=btnpC->key[0];
								btnpC->key.remove(0);
								btnpC->child.remove(0);
								solveUnderflow(btnpC);
				}
				else
				{
								btnp->key.remove(r);
								btnp->child.remove(r+1);
								solveUnderflow(btnp);
				}
				_size--;
				return true;
}

template <typename T>
void BTree<T>::solveUnderflow(BTNodePosi(T) btnp)
{
	//			cout<<"enter solveUnder"<<endl;
				if(btnp->child.size()>=(_order+1)/2)
								return;
				BTNodePosi(T) p=btnp->parent;
				if(!p)
				{
								if((!btnp->key.size()) && btnp->child[0])
								{
												_root=btnp->child[0];
												_root->parent=NULL;
												btnp->child[0]->parent=NULL;
												delete btnp;
								}
								return;
				}
				Rank r=0;
				while(p->child[r]!=btnp)
								r++;
				if(r>0)
				{
								BTNodePosi(T) lc=p->child[r-1];
								if((lc->child.size())>((_order+1)/2))
								{
												btnp->key.insert(0, p->key[r-1]);
												btnp->child.insert(0, lc->child.remove(lc->child.size()-1));
												if(btnp->child[0])
												{
																btnp->child[0]->parent=btnp;
												}
												p->key[r-1]=lc->key.remove(lc->key.size()-1);
												return;
								}
				}
				if(r<_order-1)
				{
								BTNodePosi(T) rc=p->child[r+1];
								if(rc->child.size()>(_order+1)/2)
								{
												btnp->key.insert(p->key[r]);
												btnp->child.insert(rc->child.remove(0));
												if(btnp->child[btnp->child.size()-1])
												{
																btnp->child[btnp->child.size()-1]->parent=btnp;
												}
												p->key[r]=rc->key.remove(0);
												return;
								}
				}
				if(r>0)
				{
								BTNodePosi(T) lc=p->child[r-1];
								lc->key.insert(p->key.remove(r-1));
								lc->child.insert(btnp->child.remove(0));
								while(!btnp->key.empty())
								{
												lc->key.insert(btnp->key.remove(0));
												lc->child.insert(btnp->child.remove(0));
												if(lc->child[lc->child.size()-1])
												{
																lc->child[lc->child.size()-1]->parent=lc;
												}
								}
								p->child.remove(r);
								delete btnp;
								solveUnderflow(p);
				}
				else
				{
								BTNodePosi(T) rc=p->child[r+1];
								rc->key.insert(0, p->key.remove(r));
								rc->child.insert(0, rc->child.remove(rc->child.size()-1));
								while(!btnp->key.empty())
								{
												rc->key.insert(0, btnp->key.remove(btnp->key.size()-1));
												rc->child.insert(0, btnp->child.remove(btnp->child.size()-1));
												if(rc->child[0])
												{
																rc->child[0]->parent=rc;
												}
								}
								p->child.remove(r);
								delete btnp;
								solveUnderflow(p);
				}
}

#endif
