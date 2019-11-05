typedef int Rank;
#define DEFAULT_CAPACITY 3

///////rand()///////////////////
#include <stdlib.h>

///////swap()/////////////////////
#include <algorithm>
using namespace std;
////////////////////////////////


template <typename T>
class VectorPei
{
	protected:
		Rank _size;
		int _capacity;
		T *_elem;

		void copyFrom(T const *A, Rank lo, Rank hi);
		void expand();
		void shrink();
		Rank partition(Rank lo, Rank hi);
	public:
		VectorPei(int c=DEFAULT_CAPACITY, int s=0, T v=0)
		{
			_elem=new T[_capacity=c];
			for(_size=0; _size<s;_size++)
				_elem[_size]=v;
		}
		VectorPei(T const *A, Rank n)
		{
			_size=0;
			copyFrom(A, 0, n);
		}
		VectorPei(T const *A, Rank lo, Rank hi)
		{
			_size=0;
			copyFrom(A, lo, hi);
		}
		VectorPei(VectorPei const &A)
		{
			_size=0;
			copyFrom(A._elem, 0, A._size);
		}
		VectorPei(VectorPei const &A, Rank lo, Rank hi)
		{
			_size=0;
			copyFrom(A._elem, lo, hi);
		}

		~VectorPei()
		{
			delete []_elem;

		}

		Rank size() const
		{
			return _size;
		}
		bool empty()
		{
			return !_size;
		}
		int disordered() const;
		Rank find(T const &e) const
		{
			return find(e, 0, _size);
		}
		Rank find(T const &e, Rank lo, Rank hi) const;//无序查找
		Rank search(T const &e)
		{
			return (_size<=0)?
				-1:
				search(e, 0, _size);
		}
		Rank search(T const &e, Rank lo, Rank hi) const;//有序查找
		T& operator[] (Rank r) const;
		VectorPei<T>& operator= (VectorPei<T> const& A);
		int remove(Rank lo, Rank hi);
		T remove(Rank r);
		Rank insert(Rank r, T const &e);
		Rank insert(T const &e)
		{
			return insert(_size, e);
		}
		void sort(Rank lo, Rank hi);
		void sort()
		{
			sort(0, _size);
		}
		void unsort(Rank lo, Rank hi);
		void unsort()
		{
			unsort(0, _size);
		}
		
		int deduplicate();//删除重复元素
		int uniquify_l();//删除相邻重复元素//低效版
		int uniquify_h();//高效版

		void traverse(void (*) (T &));

		template <typename VST>
		void traverse(VST &);

};

template <typename T>
void VectorPei<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
	_capacity=2*(hi-lo);
        _elem=new T[_capacity];
        while(lo<hi)
        {
                _elem[_size]=A[lo];
                _size++;
                lo++;
        }
}
 
template <typename T>
T& VectorPei<T>::operator[] (Rank r) const
{
        return _elem[r];
}

template <typename T>
VectorPei<T>& VectorPei<T>::operator= (VectorPei<T> const& A)
{
	if(_elem)
		delete []_elem;
	copyFrom(A._elem, 0, A._size);
	return *this;
}

template <typename T>
void VectorPei<T>::expand()
{
	if(_size<_capacity)
		return;
	if(_capacity<DEFAULT_CAPACITY)
		_capacity=DEFAULT_CAPACITY;
	T *oldElem=_elem;
	_elem=new T[_capacity<<1];
	for(int i=0; i<_size; i++)
	{
		_elem[i]=oldElem[i];
	}
	delete []oldElem;
}

template <typename T>
void VectorPei<T>::shrink()
{
	if(_capacity < DEFAULT_CAPACITY<<1)
		return;
	if(_size<<2 > _capacity)
		return;
	T *oldElem=_elem;
	_capacity>>=1;
	_elem=new T[_capacity];
	for(int i=0; i<_size; i++)
	{
		_elem[i]=oldElem[i];
	}
	delete []oldElem;
}

template <typename T>
void VectorPei<T>::unsort(Rank lo, Rank hi)
{
	T *v=_elem+lo;
	for(int i=hi-lo; i>1; i--)
	{
		swap(v[i-1], v[rand()%i]);
	}
}

template <typename T>
Rank VectorPei<T>::find(T const &e, Rank lo, Rank hi) const
{
	hi--;
	while(lo<=hi && e!=_elem[hi])
		hi--;
	return hi;
}

template <typename T>
Rank VectorPei<T>::insert(Rank r, T const &e)
{
	expand();
	for(int i=_size; i>r; i--)
	{
		_elem[i]=_elem[i-1];
	}
	_elem[r]=e;
	_size++;
	return r;
}

template <typename T>
int VectorPei<T>::remove(Rank lo, Rank hi)
{
	if(lo==hi)
		return 0;
	while(hi<_size)
	{
		_elem[lo]=_elem[hi];
		lo++;
		hi++;

	}
	_size=lo;
	shrink();
	return hi-lo;
}

template <typename T>
T VectorPei<T>::remove(Rank r)
{
	T e=_elem[r];
	remove(r,r+1);
	return e;
}

template <typename T>
int VectorPei<T>::deduplicate()
{
	int oldSize=_size;
	Rank i=1;
	while(i<_size)
	{
		find(_elem[i],0,i)>=0?
			remove(i):
			i++;
	}
	return oldSize-_size;
}

template <typename T>
int VectorPei<T>::uniquify_l()
{
				int oldSize=_size;
				for(int i=1; i<_size;)
				{
								(_elem[i]==_elem[i-1])?
												remove(i):
												i++;
				}
				return oldSize-_size;
}

template <typename T>
int VectorPei<T>::uniquify_h()
{
				int i=0, j=0;
				j++;
				while(j<_size)
				{
								if(_elem[i]!=_elem[j])
								{
												i++;
												_elem[i]=_elem[j];
								}
								j++;
				}
				i++;
				_size=i;
				return j-i;
}

template <typename T>
void VectorPei<T>::traverse(void (*visit)(T&))
{
	for(int i=0; i<_size; i++)
	{
		visit(_elem[i]);
	}
}

template <typename T>
template <typename VST>
void VectorPei<T>::traverse(VST &vist)
{
	for(int i=0; i<_size; i++)
	{
		vist(_elem[i]);
	}
}

template <typename T>
int VectorPei<T>::disordered() const
{
				int n=0;
				for(int i=1; i<_size; i++)
				{
								if(_elem[i-1]>_elem[i])
								{
												n++;
								}
				}
				return n;
}

template <typename T>
static Rank binSearch_A(T *_elem, T e, int lo, int hi)//log(n)
{
				while(lo < hi)
				{
								Rank mi=(lo+hi)>>1;
								if(e<_elem[mi])
								{
												hi=mi;
								}
								else if(e>_elem[mi])
								{
												lo=mi+1;
								}
								else
								{
												return mi;
								}
				}
				return -1;
}

template <typename T>
static Rank binSearch_B(T *_elem, T e, int lo, int hi)
{
				while(hi-lo>1)
				{
								Rank mi=(lo+hi)>>1;
								(e<_elem[mi])?
												hi=mi:
												lo=mi;
				}
				return (e==_elem[lo])? lo:-1;
}

template <typename T>
static Rank binSearch_C(T *_elem, T e, int lo, int hi)
{
				while(lo<hi)
				{
								Rank mi=(lo+hi)>>1;
								(e<_elem[mi])?
												hi=mi:
												lo=mi+1;
				}
				lo--;
				return lo;
}

static void getFib(int n, int *fib)
{
				fib[0]=1;
				fib[1]=0;
				fib[2]=1;
				while(fib[2]<n)
				{
								fib[2]=fib[1]+fib[2];
								fib[1]=fib[2]-fib[1];
								fib[0]=fib[1]-fib[0];
				}
}

template <typename T>
static Rank fibSearch(T *_elem, T	e, int lo, int hi)
{
				int *fib;
				fib=new int[3];
				while(lo<hi)
				{
								getFib(hi-lo, fib);
								int mi=lo+fib[1];
								if(e<_elem[mi])
								{
												hi=mi;
								}
								else if(e>_elem[mi])
								{
												lo=mi+1;
								}
								else
								{
												return mi;
								}
				}
				return -1;
}

template <typename T>
Rank VectorPei<T>::search(T const &e, Rank lo, Rank hi) const//有序查找
{
				return (hi%2)?
								binSearch_C(_elem, e, lo, hi):fibSearch(_elem, e, lo, hi);
}

template <typename T>//n^2,稳定
static void bubbleSort(T *_elem, Rank lo, Rank hi)
{
				while(lo<hi)
				{
								bool sortSign=true;
								for(int i=1; i<hi; i++)
								{
												if(_elem[i-1]>_elem[i])
												{
																swap(_elem[i-1],_elem[i]);
																sortSign=false;
												}
								}
								if(sortSign)
								{
												return;
								}
								hi--;
				}
}


template <typename T>
static void merge(T *_elem, Rank lo, Rank mi, Rank hi)
{
				int lenL=mi-lo;
				T *A=new T[lenL];
				Rank loTemp=lo;
				for(int i=0; i<lenL; i++)
				{
								A[i]=_elem[loTemp];
								loTemp++;
				}

				int lenR=hi-mi;
				T *B=_elem+mi;

				for(int i=0, j=0, k=lo; (i<lenL || j<lenR); )
				{
								if((i<lenL) && ((j>=lenR) || A[i]<=B[j]))
								{
												_elem[k]=A[i];
												k++;
												i++;
								}
								if((j<lenR) && ((i>=lenL) || A[i]>B[j]))
								{
												_elem[k]=B[j];
												k++;
												j++;
								}
				}
				delete []A;
}


template <typename T>//nlog(n)
static void mergeSort(T *_elem, Rank lo, Rank hi)
{
				if(hi-lo <=1)
								return;
				Rank mi=(lo+hi)>>1;
				mergeSort(_elem, lo, mi);
				mergeSort(_elem, mi, hi);
				merge(_elem, lo, mi, hi);
}

template <typename T>
static Rank max(T *_elem, Rank lo, Rank hi)
{
				Rank r=lo;
				for(int i=lo+1; i<hi; i++)
				{
								if(_elem[i]>_elem[r])
								{
												r=i;
								}
				}
				return r;
}

template <typename T>//n^2
static void selectionSort(T *_elem, Rank lo, Rank hi)
{
				while(hi-lo>1)
				{
								Rank r=max(_elem, lo, hi);
								hi--;
								swap(_elem[r],_elem[hi]);

				}
}

template <typename T>
static Rank partion(T *_elem, Rank lo, Rank hi)
{
				swap(_elem[lo], _elem[lo+rand()%(hi-lo)]);
				T pivot=_elem[lo];
				hi--;
				while(lo<hi)
				{
								while(lo<hi)
								{
												if(pivot<_elem[hi])
												{
																hi--;
												}
												else
												{
																_elem[lo]=_elem[hi];
																lo++;
																break;
												}
								}
								while(lo<hi)
								{
												if(pivot>_elem[lo])
												{
																lo++;
												}
												else
												{
																_elem[hi]=_elem[lo];
																hi--;
												}
								}
				}
				_elem[lo]=pivot;
				return lo;
}

template <typename T>
static void quickSort(T *_elem, Rank lo, Rank hi)//nlogn
{
				if(hi-lo<=1)
								return;
				Rank mi=partion(_elem, lo, hi);
				quickSort(_elem, lo, mi);
				quickSort(_elem, mi+1, hi);
}

template <typename T>
void VectorPei<T>::sort(Rank lo, Rank hi)
{
				switch (rand()%5)
				{
								case 1:
												bubbleSort(_elem, lo, hi);//n^2
												break;
								case 2:
												selectionSort(_elem, lo, hi);//n^2
												break;
								case 3:
												mergeSort(_elem, lo, hi);//nlogn
												break;
								case 4:
											//	heapSort(_elem, lo, hi);
												break;
								default:
												quickSort(_elem, lo, hi);//nlogn
												break;
				}
}
