#ifndef RED_BLACK_TREE
#define RED_BLACK_TREE

#include "BST.hpp"
#include <algorithm>
using namespace std;
#include <cstddef>
#include <iostream>

#define isBlack(p) ((!p) || (RB_BLACK==p->color))
#define isRed(p) (!isBlack(p))
#define blackHeightUpdate(p) ((stature(p->lc)==stature(p->rc))  \
																						 && (p->height ==(isRed(p)?stature(p->lc):(stature(p->lc)+1))))

template <typename T>
class RedBlackTree: public BST<T>
{
				protected:
								void solveDoubleRed(BinNodePeiPosi(T));
								void solveDoubleBlack(BinNodePeiPosi(T));
								int updateHeight(BinNodePeiPosi(T));

				public:
								BinNodePeiPosi(T) insert(T const &e);
								bool remove(T const &e);
};

template <typename T>
int RedBlackTree<T>::updateHeight(BinNodePeiPosi(T) bnpp)
{
				bnpp->height=max(stature(bnpp->lc), stature(bnpp->rc));
				bnpp->height=(isBlack(bnpp)?bnpp->height+1:bnpp->height);
				return bnpp->height;
}

template <typename T>
BinNodePeiPosi(T) RedBlackTree<T>::insert(T const &e)
{
				BinNodePeiPosi(T) bnpp=this->search(e);
				if(bnpp)
								return bnpp;
				bnpp=new BinNodePei<T>(e, this->_hot, NULL, NULL, -1);
				this->_size++;
				solveDoubleRed(bnpp);
				return (bnpp?bnpp:this->_hot->parent);
}

template <typename T>
void RedBlackTree<T>::solveDoubleRed(BinNodePeiPosi(T) x)
{
				if(isRoot(x))
				{
								x->color=RB_BLACK;
								x->height++;
								return;
				}
				BinNodePeiPosi(T) p=x->parent;
				if(isBlack(p))
								return;
				BinNodePeiPosi(T) u=uncle(x);
				BinNodePeiPosi(T) g=p->parent;
				if(isBlack(u))
				{
								if(isLchild(x))
								{
												p->color=RB_BLACK;
								}
								else
								{
												x->color=RB_BLACK;
								}
								g->color=RB_RED;
								BinNodePeiPosi(T) gg=g->parent;
								BinNodePeiPosi(T) r=this->rotateAt(x);
								fromParentTo(g)=r;
								r->parent=gg;
				}
				else
				{
								p->color=RB_BLACK;
								p->height++;
								u->color=RB_BLACK;
								u->height++;
								g->color=RB_RED;
								solveDoubleRed(g);
				}
}

template <typename T>
bool RedBlackTree<T>::remove(T const &e)
{
				BinNodePeiPosi(T) bnpp=this->search(e);
				if(!bnpp)
								return false;
				BinNodePeiPosi(T) r=removeAt(bnpp, this->_hot);
				this->_size--;
				if(!(this->_size))
								return true;
				if(!(this->_hot))
				{
								r->color=RB_BLACK;
								this->updateHeight(this->_root);
								return true;
				}
				if(blackHeightUpdate(this->_hot))
				{
								return true;
				}
				if(isRed(r))
				{
								r->color=RB_BLACK;
								r->height++;
								return true;
				}
				solveDoubleBlack(r);
				return true;
}

template <typename T>
void RedBlackTree<T>::solveDoubleBlack(BinNodePeiPosi(T) r)
{
				BinNodePeiPosi(T) p=(r?r->parent:this->_hot);
				if(!p)
								return;
				BinNodePeiPosi(T) s=((r==p->lc)?p->rc:p->lc);
				if(isBlack(s))
				{
								BinNodePeiPosi(T) t=NULL;
								if(isRed(s->lc))
								{
												t=s->lc;
								}
								if(isRed(s->rc))
								{
												t=s->rc;
								}
								if(t)
								{
												RBColor oldColor=p->color;
												BinNodePeiPosi(T) b=this->rotateAt(t);
												fromParentTo(p)=b;
												if(b->lc)
												{
																b->lc->color=RB_BLACK;
																this->updateHeight(b->lc);
												}
												if(b->rc)
												{
																b->rc->color=RB_BLACK;
																this->updateHeight(b->rc);
												}
												b->color=oldColor;
												this->updateHeight(b);

								}
								else
								{

												s->color=RB_RED;
												if(isRed(p))
												{
																p->color=RB_BLACK;
												}
												else
												{
																p->height--;
																solveDoubleBlack(p);
												}
								}
				}
				else
				{
								s->color=RB_BLACK;
								p->color=RB_RED;
								BinNodePeiPosi(T) t=(isLchild(s)?s->lc:s->rc);
								BinNodePeiPosi(T) b=this->rotateAt(t);
								fromParentTo(p)=b;
								this->_hot=p;
								solveDoubleBlack(r);
				}
}
#endif
