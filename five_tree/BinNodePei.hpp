#ifndef BINNODE_PEI
#define BINNODE_PEI

#include <cstddef>
#include "../four_stack/QueuePei.hpp"

#define BinNodePeiPosi(T) BinNodePei<T>*
#define stature(p) ((p)?p->height:-1)

#define isRoot(x) (!(x->parent))
#define isLchild(x) ((!isRoot(x)) && (x->parent->lc==x))
#define isRchild(x) ((!isRoot(x)) && (x->parent->rc==x))
#define hasParent(x) (!isRoot(x))
#define hasLchild(x) x->lc
#define hasRchild(x) x->rc
#define hasChild(x) (hasLchild(x) || hasRchild(x))
#define hasBothChild(x) (hasLchild(x) && hasRchild(x))
#define isLeaf(x) (!hasChild(x))
#define sibling(x) (isLchild(x)? x->parent->rc:x->parent->lc)
#define uncle(x) sibling(x->parent)
#define fromParentTo(x) (isRoot(x))? x:((isLchild(x))?x->parent->lc:x->parent->rc)

typedef enum{RB_RED, RB_BLACK} RBColor;

template <typename T>
struct BinNodePei
{
				T data;

				BinNodePeiPosi(T) parent;
				BinNodePeiPosi(T) lc;
				BinNodePeiPosi(T) rc;

				int height;
				int npl;

				RBColor color;

				BinNodePei():parent(NULL), lc(NULL), rc(NULL), npl(0), color(RB_RED){}

				BinNodePei(T e, 
												BinNodePeiPosi(T) p=NULL, 
												BinNodePeiPosi(T) lc=NULL, 
												BinNodePeiPosi(T) rc=NULL,
												int h=0,
												int l=1,
												RBColor c=RB_RED):data(e),
																					parent(p),
																					lc(lc),
																					rc(rc),
																					height(h),
																					npl(l),
																					color(c)
				{}

				int size(BinNodePeiPosi(T) x);

				BinNodePeiPosi(T) insertAsLc(T const&);
				BinNodePeiPosi(T) insertAsRc(T const&);
				BinNodePeiPosi(T) succ();

				template <typename VST>
				void travLevel(VST&);

				template <typename VST>
				void travPre(VST&);

				template <typename VST>
				void travIn(VST&);

				template <typename VST>
				void travPost(VST&);

				bool operator< (BinNodePei const &bn)
				{								
								return data<bn.data;
				}
				bool operator== (BinNodePei const &bn)
				{
								return data==bn.data;
				}
};

template <typename T>
BinNodePeiPosi(T) BinNodePei<T>::insertAsLc(T const &e)
{
				lc=new BinNodePei(e, this);
				return lc;
}

template <typename T>
BinNodePeiPosi(T) BinNodePei<T>::insertAsRc(T const &e)
{
				rc=new BinNodePei(e, this);
				return rc;
}

template <typename T>
int BinNodePei<T>::size(BinNodePeiPosi(T) x)
{
				return (x)?(1+size(x->lc)+size(x->rc)):0;
}

/////////////////////////中序遍历的直接后继//////////////
template <typename T>
BinNodePeiPosi(T) BinNodePei<T>::succ()
{
				BinNodePeiPosi(T) bnpp=this;
				if(hasRchild(bnpp))
				{
								bnpp=bnpp->rc;
								while(hasLchild(bnpp))
												bnpp=bnpp->lc;
								return bnpp;
				}
				else
				{
								while(isRchild(bnpp))
												bnpp=bnpp->parent;
								return bnpp->parent;
				}
}

template <typename T>
template <typename VST>
void BinNodePei<T>::travLevel(VST &visit)
{
				QueuePei<BinNodePeiPosi(T)> qp;
				qp.enqueue(this);

				BinNodePeiPosi(T) x;
				while(!qp.empty())
				{
								x=qp.deQueue();
								visit(x->data);
								if(hasLchild(x))
												qp.enqueue(x->lc);
								if(hasRchild(x))
												qp.enqueue(x->rc);
				}
}

#endif
