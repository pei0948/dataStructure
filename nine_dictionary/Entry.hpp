#ifndef ENTRY
#define ENTRY

template <typename K, typename V>
struct Entry
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

#endif
