////////////////////NULL包含文件///////////////
#include <cstddef>

#define ListNodePeiPosi(T) ListNodePei<T> *

template <typename T>
struct ListNodePei
{
        T data;
        ListNodePeiPosi(T) pred;
        ListNodePeiPosi(T) succ;

        ListNodePei(){}
        ListNodePei(T e, ListNodePeiPosi(T) p=NULL, ListNodePeiPosi(T) s=NULL)
                :data(e),pred(p),succ(s){}

        ListNodePeiPosi(T) insertAsPred(T const &e);
        ListNodePeiPosi(T) insertAsSucc(T const &e);
};

template <typename T>
ListNodePeiPosi(T) ListNodePei<T>::insertAsPred(T const &e) 
{
        ListNodePeiPosi(T) lnp=new ListNodePei<T>(e, pred, this);
        pred->succ=lnp;
        pred=lnp;
        return lnp;
}

template <typename T>
ListNodePeiPosi(T) ListNodePei<T>::insertAsSucc(T const &e) 
{
        ListNodePeiPosi(T) lnp=new ListNodePei(e, this, succ);
        succ->pred=lnp;
        succ=lnp;
        return lnp;
}

