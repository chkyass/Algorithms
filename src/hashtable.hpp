#ifndef __hashtable__
#define __hashtable__
#include <vector>
#include <cmath>
#include <functional>
#include <iostream>

typedef uint_fast64_t uint64;


template <class K, class V>
class hashtable
{
  private:
    // m_ prime
    uint64 m_;
    uint64 size_ = 0;
    std::vector<std::pair<K,V>* >* table_;
    void rehash(uint64);
    uint64 hash(const K&);

  public:
    hashtable(unsigned long long m=7);
    ~hashtable();
    void insert(K, V);
    V* get(const K&);
    bool remove(const K&);
    bool isPrime(const uint64&);
    uint64 nextPrime(uint64);
    void applyToEntries(const std::function<void (std::pair<K,V>* p)>, uint64);
};

template <class K, class V> hashtable<K,V>::hashtable(unsigned long long m): m_(m),table_(new std::vector<std::pair<K,V>* >[m])
{}

template <class K, class V> hashtable<K,V>::~hashtable()
{
  applyToEntries([](std::pair<K,V>* p)
  {
    delete p;
  }, m_);
  delete [] table_;
}

template <class K, class V> void hashtable<K,V>::applyToEntries(std::function<void(std::pair<K,V>*)> f, uint64 size)
{
  for(size_t i = 0; i < size ; i++)
  {
    for(auto& p : table_[i])
    {
      f(p);
    }
  }
}

template <class K, class V> uint64 hashtable<K,V>::hash(const K& key)
{
  return (uint64) key % m_;
}

template <class K, class V> uint64 hashtable<K,V>::nextPrime(uint64 val)
{
  if(val <= 2)
    return val+1;
  
  if((val & 0x1) == 0)
    val++;

  uint64 prime;
  // skip pair values
  while(!(prime=isPrime(val+=2))){};
  
  return val;
}

template <class K, class V> bool hashtable<K,V>::isPrime(const uint64& val)
{
  double square_root = std::sqrt(val);
  for(uint64 i = 2; i <= square_root; i++)
  {
    if(val%i == 0)
      return false;
  }
  return true;
}

template <class K, class V> void hashtable<K,V>::rehash(uint64 new_m)
{
  std::vector<std::pair<K,V>* >* new_table = new std::vector<std::pair<K,V>* > [new_m];
  uint64 old_m = m_;
  m_ = new_m;

  // move entries to new table;
  applyToEntries([new_table,this](std::pair<K,V>* p) -> void {
      uint64 h = this->hash(p->first);
      new_table[h].push_back(p);
    }, old_m);

  delete [] table_;
  table_ = new_table;
}

template <class K, class V> void hashtable<K,V>::insert(K key, V val)
{
  uint64 h = hash(key);

  //if key already present update value
  for(auto& pair : table_[h])
  {
    if(pair->first == key)
    {
      pair->second = val;
      return;
    }
  }

  if(++size_ == m_)
  {
    // add one to make nextPrime parameter odd
    rehash(nextPrime(m_*2));
    h = hash(key);
  }

  table_[h].push_back(new std::pair<K,V> (key, val));
}

template <class K, class V> V* hashtable<K,V>::get(const K& key)
{
  uint64 h = hash(key);
  for(auto& e : table_[h])
    if(e->first == key)
      return &e->second;
  
  return nullptr;
}

template <class K, class V> bool hashtable<K,V>::remove(const K& key)
{
  uint64 h = hash(key);
  for(size_t i = 0; i < table_[h].size(); i++)
  {
    if(table_[h][i]->first == key)
    {
      delete table_[h][i];
      table_[h].erase(table_[h].begin()+i); 
      if(--size_ == m_/4)
        rehash(nextPrime(m_/2));
      return true;
    }
  }

  return false;  
}

#endif