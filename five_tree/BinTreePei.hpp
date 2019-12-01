#ifndef BINTREE_PEI
#define BINTREE_PEI
///////////////////////max()/////////////////
#include <algorithm>

#include <cstddef>

#include "../four_stack/StackPei.hpp"
#include "BinNodePei.hpp"

template <typename T>
class BinTreePei
{
				protected:
								int _size;
								BinNodePeiPosi(T) _root;
								virtual int updateHeight(BinNodePeiPosi(T) bnpp);
								void updateHeightAbove(BinNodePeiPosi(T) bnpp);

				public:
								BinTreePei():_size(0),_root(NULL){}
								~BinTreePei()
								{
												if(_size>0)
																remove(_root);
								}

								int size()
								{
												return _size;
								}
								bool empty() const
								{
												return (!_root);
								}

								BinNodePeiPosi(T) root()
								{
												return _root;
								}
								BinNodePeiPosi(T) insertAsRoot(T const &e);
								BinNodePeiPosi(T) insertAsLc(BinNodePeiPosi(T) bnpp, T const &e);
								BinNodePeiPosi(T) insertAsRc(BinNodePeiPosi(T) bnpp, T const &e);
								BinNodePeiPosi(T) attachAsLc(BinNodePeiPosi(T) bnpp, BinTreePei<T>* &t);
								BinNodePeiPosi(T) attachAsRc(BinNodePeiPosi(T) bnpp, BinTreePei<T>* &t);

								int remove(BinNodePeiPosi(T) bnpp);
								int removeAt(BinNodePeiPosi(T) x);
								BinTreePei<T>* secede(BinNodePeiPosi(T) x);

								template <typename VST>
								void travLevel(VST &visit)
								{
												if(_root)
												{
																_root->travLevel(visit);
												}
								}
								template <typename VST>
								void travPre_R(BinNodePeiPosi(T) x, VST &visit);
								template <typename VST>
								void travPre_I(BinNodePeiPosi(T) x, VST &visit);
								
								template <typename VST>
								void travIn_R(BinNodePeiPosi(T) x, VST &visit);
								template <typename VST>
								void travIn_I1(BinNodePeiPosi(T) x, VST &visit);
								template <typename VST>
								void travIn_I2(BinNodePeiPosi(T) x, VST &visit);
								template <typename VST>
								void travIn_I3(BinNodePeiPosi(T) x, VST &visit);
								
								template <typename VST>
								void travPost_R(BinNodePeiPosi(T) x, VST &visit);
							  template <typename VST>
								void travPost_I(BinNodePeiPosi(T) x, VST &visit);

								bool operator< (BinTreePei<T> const &t)
								{
												return (_root && t._root && _root<t._root);
								}
								bool operator== (BinTreePei<T> const &t)
								{
												return (_root && t._root && _root==t._root);
								}
};

template <typename T>
int BinTreePei<T>::updateHeight(BinNodePeiPosi(T) x)
{
				if(x->lc || x->rc)
				{
								x->height=1+std::max(stature(x->lc), stature(x->rc));
				}
				else
				{
								x->height=0;
				}

				return x->height; 
}

template <typename T>
void BinTreePei<T>::updateHeightAbove(BinNodePeiPosi(T) x)
{
				while(x)
				{
								updateHeight(x);
								x=x->parent;
				}
}

template <typename T>
BinNodePeiPosi(T) BinTreePei<T>::insertAsRoot(T const &e)
{
				_root=new BinNodePei<T>(e);
				_size=1;
				return _root;
}

template <typename T>
BinNodePeiPosi(T) BinTreePei<T>::insertAsLc(BinNodePeiPosi(T) x, T const &e)
{
				x->insertAsLc(e);
				_size++;
				updateHeightAbove(x);
				return x->lc;
}

template <typename T>
BinNodePeiPosi(T) BinTreePei<T>::insertAsRc(BinNodePeiPosi(T) x, T const &e)
{
				x->insertAsRc(e);
				_size++;
				updateHeightAbove(x);
				return x->rc;

}

template <typename T>
int BinTreePei<T>::removeAt(BinNodePeiPosi(T) x)
{
				if(x)
				{
								fromParentTo(x)=NULL;
								return	1+removeAt(x->lc)+removeAt(x->rc);
				}
				else
				{
								return 0;
				}
}

template <typename T>
int BinTreePei<T>::remove(BinNodePeiPosi(T) x)
{
				int n=removeAt(x);
				_size=_size-n;
				return n;
}

template <typename T>
BinNodePeiPosi(T) BinTreePei<T>::attachAsLc(BinNodePeiPosi(T) x, BinTreePei<T>* &b)
{
			x->lc=b->_root;
			x->lc->parent=x;
			_size=_size+b->_size;
			updateHeightAbove(x);
			b->_root=NULL;
			b->_size=0;
			b=NULL;
			return x;
}

template <typename T>
BinNodePeiPosi(T) BinTreePei<T>::attachAsRc(BinNodePeiPosi(T) x, BinTreePei<T>* &b)//* 是为了后面赋值NULL释放
{
				x->rc=b->_root;//相当于找个新的变量来储存这个地址
				x->rc->parent=x;

				_size=_size+b->_size;

				updateHeightAbove(x);

				b->_root=NULL;
				b->_size=0;
				b=NULL;

				return x;
}

template <typename T>
BinTreePei<T>* BinTreePei<T>::secede(BinNodePeiPosi(T) x)
{
				fromParentTo(x)=NULL;
				updateHeightAbove(x->parent);
				x->parent=NULL;
				BinTreePei<T>* b=new BinTreePei<T>();
				b->_root=x;
				b->_size=x->size(x);
				_size=_size-b->_size;

				return b;
}

template <typename T> 
template <typename VST>
void BinTreePei<T>::travPre_R(BinNodePeiPosi(T) x, VST &visit)
{
				if(!x)
								return;
				visit(x->data);
				travPre_R(x->lc, visit);
				travPre_R(x->rc, visit);
}

template <typename T, typename VST>
void static visitLeftBranch(BinNodePeiPosi(T) x, StackPei<BinNodePeiPosi(T)> &s, VST &visit)
{
				while(x)
				{
								visit(x->data);
								if(x->rc)
										s.push(x->rc);
								x=x->lc;
				}
}

template <typename T>
template <typename VST>
void BinTreePei<T>::travPre_I(BinNodePeiPosi(T) x, VST &visit)
{
				StackPei<BinNodePeiPosi(T)> s;
				while(true)
				{
								visitLeftBranch(x, s, visit);
								if(s.empty())
												break;
								x=s.pop();
				}
}


template <typename T> 
template <typename VST>
void BinTreePei<T>::travIn_R(BinNodePeiPosi(T) x, VST &visit)
{
				if(!x)
								return;
				travIn_R(x->lc, visit);
				visit(x->data);
				travIn_R(x->rc, visit);
}

template <typename T>
void static goLeftBranch(BinNodePeiPosi(T) x, StackPei<BinNodePeiPosi(T)> &s)
{
				while(x)
				{
								s.push(x);
								x=x->lc;
				}
}

template <typename T>
template <typename VST>
void BinTreePei<T>::travIn_I1(BinNodePeiPosi(T) x, VST &visit)
{
				StackPei<BinNodePeiPosi(T)> s;
				while(true)
				{
								goLeftBranch(x, s);
								if(s.empty())
												break;
								x=s.pop();
								visit(x->data);
								x=x->rc;
				}
}
template <typename T>
template <typename VST>
void BinTreePei<T>::travIn_I2(BinNodePeiPosi(T) x, VST &visit)
{
				StackPei<BinNodePeiPosi(T)> sp;

				while(true)
				{
								if(x)
								{
												sp.push(x);
												x=x->lc;
								}
								else if(!sp.empty())
								{
												x=sp.pop();
												visit(x->data);
												x=x->rc;
								}
								else
								{
												break;
								}
				}
}
template <typename T>
template <typename VST>
void BinTreePei<T>::travIn_I3(BinNodePeiPosi(T) x, VST &visit)
{
				bool traceBack=false;
				while(true)
				{
								if((!traceBack) && hasLchild(x))
								{
												x=x->lc;
								}
								else
								{
												visit(x->data);
												if(hasRchild(x))
												{
																x=x->rc;
																traceBack=false;
												}
												else
												{
																x=x->succ();
																if(!x)
																				break;
																traceBack=true;
												}
								}
				}
}

template <typename T> 
template <typename VST>
void BinTreePei<T>::travPost_R(BinNodePeiPosi(T) x, VST &visit)
{
				if(!x)
								return;
				travPost_R(x->lc, visit);
				travPost_R(x->rc, visit);
				visit(x->data);
}

template <typename T>
void static goLeft(StackPei<BinNodePeiPosi(T)> &sp)
{
				BinNodePeiPosi(T) x=sp.top();
				while(x)
				{
								if(hasLchild(x))
								{
												if(hasRchild(x))
												{
																sp.push(x->rc);
												}
												x=x->lc;
								}
								else
								{
												x=x->rc;
								}
							  sp.push(x);
				}
				sp.pop();
}

template <typename T>
template <typename VST>
void BinTreePei<T>::travPost_I(BinNodePeiPosi(T) x, VST &visit)
{
				StackPei<BinNodePeiPosi(T)> sp;
				sp.push(x);
				while(!sp.empty())
				{
								if(sp.top()!=x->parent)
								{
												goLeft(sp);
								}
								x=sp.pop();
								visit(x->data);
				}
}

#endif
