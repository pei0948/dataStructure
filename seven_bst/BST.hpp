#ifndef BST_TREE
#define BST_TREE

template <typename K, typename V>
struct EntryP
{
				K key;
				V value;
				EntryP(K k, V v):key(k), value(v)
				{}
				EntryP(EntryP<K, V> const &e):key(e.key), value(e.value)
				{}

				bool operator== (EntryP<K, V> const &e)
				{
								return (key==e.key);
				}
				bool operator< (EntryP<K, V> const &e)
				{
								return (key<e.key);
				}
				bool operator> (EntryP<K, V> const &e)
				{
								return (key>e.key);
				}
				bool operator!= (EntryP<K, V> const &e)
				{
								return (key!=e.key);
				}
};

#include <cstddef>

#include "../five_tree/BinTreePei.hpp"

#define tallerChild(x) ((stature(x->lc)>stature(x->rc))?\
								x->lc:\
								((stature(x->lc)<stature(x->rc))?\
								x->rc:\
								(isLchild(x)?x->lc:x->rc)))

template <typename T>
class BST:public BinTreePei<T>
{
				protected:
								BinNodePeiPosi(T) _hot;
								BinNodePeiPosi(T) connect34(BinNodePeiPosi(T), BinNodePeiPosi(T), BinNodePeiPosi(T),
																BinNodePeiPosi(T), BinNodePeiPosi(T), BinNodePeiPosi(T), BinNodePeiPosi(T));
								BinNodePeiPosi(T) rotateAt(BinNodePeiPosi(T) &x);

				public:
						 virtual BinNodePeiPosi(T)& search(T const &e);
						 virtual BinNodePeiPosi(T) insert(T const &e);
						 virtual bool remove(T const &e);
};

template <typename T>
BinNodePeiPosi(T)& BST<T>::search(T const &e)
{
				_hot=NULL;
				return searchIn(this->_root, e, _hot);
}

template <typename T>
static BinNodePeiPosi(T)& searchIn(BinNodePeiPosi(T) &v, T const &e, BinNodePeiPosi(T) &hot)
{
				if(!v || e==v->data)
								return v;
				hot=v;
				return searchIn(((e<v->data)?v->lc:v->rc), 
												e, 
												hot);
}

template <typename T>
BinNodePeiPosi(T) BST<T>::insert(T const &e)
{
				BinNodePeiPosi(T) &x=search(e);
				if(x)
				{
								return x;
				}
				x=new BinNodePei<T>(e, _hot);
				this->_size++;
				this->updateHeightAbove(_hot);
				return x;
}

template <typename T>
bool BST<T>::remove(T const &e)
{
BinNodePeiPosi(T) &x=search(e);
				if(!x)
								return false;
				removeAt(x, _hot);
				this->_size--;
				this->updateHeightAbove(_hot);
				return true;
}
template <typename T>
static BinNodePeiPosi(T) removeAt(BinNodePeiPosi(T) &x, BinNodePeiPosi(T) &hot)
{
				BinNodePeiPosi(T) w=x;
				BinNodePeiPosi(T) succ=NULL;
				if(!hasLchild(x))
				{
								succ=x=x->rc;
				}
				else if(!hasRchild(x))
				{
								succ=x=x->lc;
				}
				else
				{
								w=x->succ();
								swap(x->data, w->data);
								BinNodePeiPosi(T) u=w->parent;
								succ=w->rc;
								(u==x)?u->rc=w->rc:
												u->lc=w->rc;
				}
				hot=w->parent;
				if(succ)
								succ->parent=hot;
				delete w;
				return succ;
}

template <typename T>
BinNodePeiPosi(T) BST<T>::connect34(BinNodePeiPosi(T) a, BinNodePeiPosi(T) b, BinNodePeiPosi(T) c,
								BinNodePeiPosi(T) t0, BinNodePeiPosi(T) t1, BinNodePeiPosi(T) t2, BinNodePeiPosi(T) t3)
{
				a->lc=t0;
				if(t0)
								t0->parent=a;
				a->rc=t1;
				if(t1)
								t1->parent=a;
				this->updateHeight(a);

				c->lc=t2;
				if(t2)
								t2->parent=c;
				c->rc=t3;
				if(t3)
								t3->parent=c;
				this->updateHeight(c);

				b->lc=a;
				b->rc=a;
				this->updateHeight(b);

				return b;
}

template <typename T>
BinNodePeiPosi(T) BST<T>::rotateAt(BinNodePeiPosi(T) &x)
{
				BinNodePeiPosi(T) &p=x->parent;
				BinNodePeiPosi(T) &g=p->parent;

				if(isLchild(p))
				{
								if(isLchild(x))
								{
												return connect34(x, p, g, x->lc, x->rc, p->rc, g->rc);
								}
								else
								{
												return connect34(p, x, g, p->lc, x->lc, x->rc, g->rc);
								}
				}
				else
				{
								if(isRchild(x))
								{
												return connect34(g, p, x, g->lc, p->lc, x->lc, x->rc);
								}
								else
								{
												return connect34(g, x, p, g->lc, x->lc, p->lc, p->rc);
								}
				}
}

#endif
