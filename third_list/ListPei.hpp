////////////////////NULL包含文件///////////////
#include <cstddef>
#include <stdlib.h>

#include "ListNodePei.hpp"

typedef int Rank;

template <typename T>
class ListPei
{
				private:
								int _size;
								ListNodePeiPosi(T) header;
								ListNodePeiPosi(T) trailer;

				protected:
								void init();
								int clear();
								void copyNodes(ListNodePeiPosi(T), int);


				public:
								ListPei()
								{
												init();
								}
								
								ListPei(T const *a, int n);
								ListPei(ListPei<T> const &L);
								ListPei(ListPei<T> const &L, Rank r, int n);
								ListPei(ListNodePeiPosi(T) p, int n);

								~ListPei();
								Rank size() const
								{
												return _size;
								}
								
								bool empty() const
								{
												return _size<=0;
								}

								ListNodePeiPosi(T) operator[] (Rank r) const;

								ListNodePeiPosi(T) first() const
								{
												return header->succ;
								}
								ListNodePeiPosi(T) last() const
								{
												return trailer->pred;
								}

								bool valid(ListNodePeiPosi(T) p)
								{
												return p && (p!=header) && (p!=trailer);
								}

								int disordered() const;

								ListNodePeiPosi(T) find(T const &e) const //无序查找
								{
												return find(e, _size, trailer);
								}
								ListNodePeiPosi(T) find(T const &e, int n, ListNodePeiPosi(T) p) const;

								ListNodePeiPosi(T) search(T const &e) const
								{
												return search(e, _size, trailer);
								}
								ListNodePeiPosi(T) search(T const &e, int n, ListNodePeiPosi(T) p) const;

								ListNodePeiPosi(T) selectMax(ListNodePeiPosi(T) p, int n);
								ListNodePeiPosi(T) selectMax()
								{
												return selectMax(header->succ, _size);
								}

								ListNodePeiPosi(T) insertAsFirst(T const &e);
								ListNodePeiPosi(T) insertAsLast(T const &e);

								ListNodePeiPosi(T) insertA(ListNodePeiPosi(T) p, T const &e);
								ListNodePeiPosi(T) insertB(ListNodePeiPosi(T) p, T const &e);

								T remove(ListNodePeiPosi(T) p);

								void sort(ListNodePeiPosi(T) p, int n);
								void sort()
								{
												sort(first(), _size);
								}

								int deDuplicate();//无序去重
								int uniquify();//有序去重

								void reverse();

								void traverse(void (*)(T &));

								template <typename VST>
								void traverse(VST &);
};

template <typename T>
void ListPei<T>::init()
{
				header=new ListNodePei<T>;
				trailer=new ListNodePei<T>;

				header->pred=NULL;
				header->succ=trailer;

				trailer->pred=header;
				trailer->succ=NULL;

				_size=0;
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::operator[] (Rank r) const
{
				ListNodePeiPosi(T) lnp=first();
				while(r>0)
				{
								lnp=lnp->succ;
								r--;
				}
				return lnp;
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::find(T const &e, int n, ListNodePeiPosi(T) p) const
{
				while(n>0 && p->pred != header)
				{
								p=p->pred;
								if(e==p->data)
												return p;
								n--;
				}
				return NULL;
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::insertAsFirst(T const &e)
{
				_size++;
				return header->insertAsSucc(e);
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::insertAsLast(T const &e)
{
				_size++;
				return trailer->insertAsPred(e);
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::insertA(ListNodePeiPosi(T) lnp, T const &e)
{
				_size++;
				return lnp->insertAsSucc(e);
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::insertB(ListNodePeiPosi(T) lnp, T const &e)
{
				_size++;
				return lnp->insertAsPred(e);
}

template <typename T>
void ListPei<T>::copyNodes(ListNodePeiPosi(T) lnp, int n)
{
				init();
				while(n>0)
				{
								insertAsLast(lnp->data);
								lnp=lnp->succ;
								n--;
				}
}

template <typename T>
ListPei<T>::ListPei(ListPei<T> const &lp)
{
				copyNodes(lp.first(), lp._size);
}

template <typename T>
ListPei<T>::ListPei(ListPei<T> const &lp, Rank r, int n)
{
				copyNodes(lp[r], n);
}

template <typename T>
ListPei<T>::ListPei(T const *a, int n) 
{
				init();
				for(int i=0; i<n; i++)
				{
								insertAsLast(a[i]);
				}
}

template <typename T>
T ListPei<T>::remove(ListNodePeiPosi(T) p)
{
				T e=p->data;
				p->pred->succ=p->succ;
				p->succ->pred=p->pred;
				delete p;
				_size--;
				return e;
}

template <typename T>
ListPei<T>::~ListPei()
{
				clear();
				delete header;
				delete trailer;
}

template <typename T>
int ListPei<T>::clear()
{
				int oldSize=_size;
				while(_size>0)
				{
								remove(header->succ);
				}
				return oldSize;
}

template <typename T>
int ListPei<T>::deDuplicate()
{
				if(_size<2)
								return 0;
				int oldSize=_size;
				ListNodePeiPosi(T) p=header->succ;
				int r=0;
				while(p!=trailer)
				{
								ListNodePeiPosi(T) q=find(p->data, r, p);
								if(q)
								{
												remove(q);
												r--;
								}
								else
								{
												p=p->succ;
												r++;
								}
				}
				return oldSize-_size;
}

template <typename T>
void ListPei<T>::traverse(void (*visit)(T &))
{
				ListNodePeiPosi(T) p=header->succ;
				while(p!=trailer)
				{
								visit(p->data);
								p=p->succ;
				}
}

template <typename T>
template <typename VST>
void ListPei<T>::traverse(VST &visit)
{
				ListNodePeiPosi(T) p=header->succ;
				while(p!=trailer)
				{
								visit(p->data);
								p=p->succ;
				}
}

template <typename T>
int ListPei<T>::uniquify()
{
				if(_size<2)
								return 0;
				int oldSize=_size;
				ListNodePeiPosi(T) p=header;
				ListNodePeiPosi(T) q=p->succ;
				while(q!=trailer)
				{
								if(p->data!=q->data)
								{
												p=q;
												q=p->succ;
								}
								else
								{
												remove(q);
												q=p->succ;
								}
				}
				return oldSize-_size;
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::search(T const &e, int n, ListNodePeiPosi(T) p) const
{
				ListNodePeiPosi(T) pTemp=p;
				while(n > 0)
				{
								pTemp=pTemp->pred;
								if(pTemp->data <= e)
												break;
								n--;
				}
				return (pTemp->data <= e)? pTemp : pTemp->pred;
}

template <typename T>
void static swapNode(ListNodePeiPosi(T) lnpp1, ListNodePeiPosi(T) lnpp2)
{
				T temp=lnpp1->data;
				lnpp1->data=lnpp2->data;
				lnpp2->data=temp;
}

template <typename T>
void static bubbleSort(ListNodePeiPosi(T) lnpp, int n)//n^2
{
				bool sortSign;
				ListNodePeiPosi(T) lnppTemp;
				while(n>1)
				{
								sortSign=true;
								lnppTemp=lnpp;
								for(int i=0; i<n-1; i++)
								{
												if(lnppTemp->data > lnppTemp->succ->data)
												{
																swapNode(lnppTemp, lnppTemp->succ);
																sortSign=false;
												}
												lnppTemp=lnppTemp->succ;
								}
								if(sortSign)
												return;
								n--;
				}
}

template <typename T>
void insertSort(ListPei<T> *lp, ListNodePeiPosi(T) p, int n)//n^2
{
				p=p->succ;
				for(int i=1; i<n; i++)
				{
								ListNodePeiPosi(T) q=lp->search(p->data, i, p);
								if(q->succ!=p)
								{
												lp->insertA(q, p->data);
												p=p->succ;
												lp->remove(p->pred);
								}
								else
								{
												p=p->succ;
								}
				}
}

template <typename T>
ListNodePeiPosi(T) ListPei<T>::selectMax(ListNodePeiPosi(T) lnpp, int n)
{
				ListNodePeiPosi(T) max=lnpp;
				lnpp=lnpp->succ;
				for(int i=1; i<n; i++)
				{
								if(lnpp->data > max->data)
												max=lnpp;
								lnpp=lnpp->succ;
				}
				return max;
}

template <typename T>
void static selectSort(ListPei<T> *lp, ListNodePeiPosi(T) lnpp, int n)//n^2
{
				ListNodePeiPosi(T) trail=lnpp;
				for(int i=1; i<n; i++)
								trail=trail->succ;
				while(n>1)
				{
								ListNodePeiPosi(T) max=lp->selectMax(lnpp, n);
								swapNode(max, trail);
								trail=trail->pred;
								n--;
				}
}

template <typename T>
void static merge(ListPei<T> *lp, ListNodePeiPosi(T) &lnppA, int a, ListNodePeiPosi(T) lnppB, int b)
{
				ListNodePeiPosi(T) oldLnppPred=lnppA->pred;
				while(b>0)
				{
								if(a>0 && (lnppA->data <= lnppB->data))
								{
												lnppA=lnppA->succ;
												a--;
												if(lnppA==lnppB)
																break;
								}
								else
								{
												lnppB=lnppB->succ;
												lp->insertB(lnppA, lp->remove(lnppB->pred));
												b--;
								}

				}
				lnppA=oldLnppPred->succ;

}

template <typename T>
void static mergeSort(ListPei<T> *lp, ListNodePeiPosi(T) &lnpp, int n)//一定要有&,否则报错,amazing (nlogn)
{
				if(n<2)
								return;
				int mi=n>>1;
				ListNodePeiPosi(T) lnppMi=lnpp;
				for(int i=0; i<mi; i++)
				{
								lnppMi=lnppMi->succ;
				}

				mergeSort(lp, lnpp, mi);
				mergeSort(lp, lnppMi, n-mi);
				merge(lp, lnpp, mi, lnppMi, n-mi);
}

template <typename T>
Rank static partion(ListNodePeiPosi(T) lnpp, int n)//前面不能有&,否则oldLnppPred始终跟在lnpp前面(nlogn)
{
				ListNodePeiPosi(T) oldLnppPred=lnpp->pred;
				Rank r=rand()%n;
				ListNodePeiPosi(T) trail=lnpp;
				for(int i=1; i<n; i++)
				{
								trail=trail->succ;
								if(i==r)
								{
												swapNode(lnpp, trail);
								}
				}
	
				int mi=0;
				T pivot=lnpp->data;
				while(trail!=lnpp)
				{
								while(trail != lnpp)
								{
												if(trail->data <= pivot)
												{
																lnpp->data=trail->data;
																lnpp=lnpp->succ;
																mi++;
																break;
												}
												else
												{
																trail=trail->pred;
												}
								}
								while(trail != lnpp)
								{
												if(lnpp->data >= pivot)
												{
																trail->data=lnpp->data;
																trail=trail->pred;
																break;
												}
												else
												{
																lnpp=lnpp->succ;
																mi++;
												}
								}
				}
				lnpp->data=pivot;
				lnpp=oldLnppPred->succ;
				return mi;

}

template <typename T>
void static quickSort(ListNodePeiPosi(T) &lnpp, int n)
{
				if(n<2)
								return;
				Rank pivot=partion(lnpp, n);
				ListNodePeiPosi(T) lnppPivot=lnpp;
				for(int i=0; i<pivot; i++)
				{
								lnppPivot=lnppPivot->succ;
				}
				quickSort(lnpp, pivot);
				quickSort(lnppPivot->succ, n-pivot-1);
}

template <typename T>
void ListPei<T>::sort(ListNodePeiPosi(T) p, int n)
{
				quickSort(p, n);
}
