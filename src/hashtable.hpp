#ifndef __hashtable__
#define __hashtable__
#include <vector>

typedef uint_fast64_t uint;

template <class K, class V>
class hashtable
{
  private:
    // m_ is prime
    uint m_;
    struct pair 
    {
      K key;
      V val;
    };
    std::vector<pair>* table_;
    
    uint hash(K&);
    uint findNextPrime(uint);
    bool isPrime(uint);
    void rehash();

  public:
    hashtable(unsigned long long m=7);
    ~hashtable();
    void insert(K&);
    bool get(K&);
    void remove(K&);
    void extend();
};

template <class K, class V> hashtable<K,V>::hashtable(unsigned long long m): m_(m), table_(new table[m])
{
}

template <class K, class V> uint hashtable<K,V>::hash(K& key)
{
  return (uint) key % m_;
}

template <class K, class V> bool hashtable<K,V>::isPrime(uint i)
{
  
}


#endif