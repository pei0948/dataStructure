#ifndef SPLAY_BST
#define SPLAY_BST

#include <cstddef>
#include <iostream>
using namespace std;

#include "BST.hpp"

template <typename T>
inline void attachLchild(T &v, T &lc)
{
				v->lc=lc;
				if(lc)
								lc->parent=v;
}

template <typename T>
inline void attachRchild(T &v, T &rc)
{
				v->rc=rc;
				if(rc)
								rc->parent=v;
}

template <typename T>
class Splay: public BST<T>
{
				protected:
								BinNodePeiPosi(T) splay(BinNodePeiPosi(T) &v);

				public:
								BinNodePeiPosi(T)& search(T const &e);
								BinNodePeiPosi(T) insert(T const &e);
								bool remove(T const &e);
};

template <typename T>
BinNodePeiPosi(T) Splay<T>::splay(BinNodePeiPosi(T) &v)
{
				if(!v)
								return NULL;
				BinNodePeiPosi(T) p;
				BinNodePeiPosi(T) g;

				while((p=v->parent) && (g=p->parent))//短路特性,p是否存在,用得很漂亮
				{
								BinNodePeiPosi(T) gg=g->parent;
								if(isLchild(v))
								{
												if(isLchild(p))
												{
																attachLchild(g, p->rc);
																attachLchild(p, v->rc);
																attachRchild(p, g);
																attachRchild(v, p);
												}
												else
												{
																attachRchild(g, v->lc);
																attachLchild(p, v->rc);
																attachLchild(v, g);
																attachRchild(v, p);
												}
								}
								else
								{
												if(isLchild(p))
												{
																attachLchild(g, v->rc);
																attachRchild(p, v->lc);
																attachLchild(v, p);
																attachRchild(v, g);
												}
												else
												{
																attachRchild(g, p->lc);
																attachRchild(p, v->lc);
																attachLchild(p, g);
																attachLchild(v, p);
												}
								}

								v->parent=gg;
								if(gg)
								{
												(g==gg->lc)?gg->lc=v:gg->rc=v;
								}
								
	//							cout<<v->data<<endl;

								this->updateHeight(g);
								this->updateHeight(p);
								this->updateHeight(v);

				}

				if(p)
				{
								if(isLchild(v))
								{
												attachLchild(p, v->rc);
												attachRchild(v, p);
								}
								else
								{
												attachRchild(p, v->lc);
												attachLchild(v, p);
								}
								this->updateHeight(p);
								this->updateHeight(v);
				}

			  v->parent=NULL;
				return v;
}

template <typename T>
BinNodePeiPosi(T)& Splay<T>::search(T const &e)
{
				this->_hot=NULL;
				BinNodePeiPosi(T) bnpp=searchIn(this->_root, e, this->_hot);
	//			cout<<(bnpp?bnpp->data:0)<<endl;
				this->_root=splay(bnpp?bnpp:this->_hot);
				return this->_root;
}

template <typename T>
BinNodePeiPosi(T) Splay<T>::insert(T const &e)
{
				if(!this->_root)
				{
								this->_root=new BinNodePei<T>(e);
								this->_size++;
								return this->_root;
				}
				BinNodePeiPosi(T) bnpp=search(e);
				
				if(e==bnpp->data)
				{
								return bnpp;
				}
				else if(e<bnpp->data)
				{
								this->_root=new BinNodePei<T>(e, NULL, bnpp->lc, bnpp);
								if(hasLchild(bnpp))
								{
												bnpp->lc->parent=this->_root;
												bnpp->lc=NULL;
								}
								bnpp->parent=this->_root;
								this->_size++;
				}
				else
				{
								this->_root=new BinNodePei<T>(e, NULL, bnpp, bnpp->rc);
								if(hasRchild(bnpp))
								{
												bnpp->rc->parent=this->_root;
												bnpp->rc=NULL;
								}
								bnpp->parent=this->_root;
								this->_size++;
				}
				this->updateHeightAbove(bnpp);
				return this->_root;
}

template <typename T>
bool Splay<T>::remove(T const &e)
{
				if(!this->_root)
								return false;
				BinNodePeiPosi(T) bnpp=search(e);
				if(bnpp->data!=e)
								return false;
				if(!hasLchild(bnpp))
				{
								this->_root=bnpp->rc;
								if(this->_root)
												this->_root->parent=NULL;
				}
				else if(!hasRchild(bnpp))
				{
								this->_root=bnpp->lc;
								if(this->_root)
												this->_root->parent=NULL;
				}
				else
				{
								this->_root=bnpp->rc;
								this->_root->parent=NULL;
								bnpp->rc=NULL;
								search(e);
								this->_root->lc=bnpp->lc;
								bnpp->lc->parent=this->_root;
				}

				if(this->_root)
								this->updateHeight(this->_root);
				delete(bnpp);
				return true;
}

#endif
