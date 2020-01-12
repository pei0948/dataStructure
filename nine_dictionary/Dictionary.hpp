#ifndef DICTIONARY
#define DICTIONARY

template <typename K, typename V>
class Dictionary
{
				virtual int size() const=0;
				virtual bool put(K, V)=0;
				virtual V* get(K)=0;
				virtual bool remove(K k)=0;
};

#endif
