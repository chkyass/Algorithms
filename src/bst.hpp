#ifndef bst_h
#define bst_h

#include <iostream>

template<class K>
struct node{
      node *left_;
      node *right_;
      K key_;
};

/*
  invariant: left subtree is smaller, right subtree is bigger
*/
template <class K, class N=node<K> >
class bst
{
    N *left_;
    N *right_;
    K key_;
    size_t size_;
    bool insertNode(N*, const K&, N*);
    void leftFirstDelete(N*);

  public:
    bst(K e, N *left=nullptr, N *right=nullptr);
    bool contain(const K&);
    size_t size() const;
    virtual void insert(const K&);
    virtual ~bst();
    void operator=(bst) = delete;
    bst(bst&) = delete;
};

template <class K, class N> bst<K,N>::bst(K k, N *left, N *right):left_(left), right_(right), key_(k)
{
  size_ = 1;
}

/*
  Implementation of the binary search
  take the root node of the tree as first paramter
  the key to insert
  and node to insert
  return true the new node is inserted
*/
template <class K, class N> bool bst<K, N>::insertNode(N *node, const K &e, N *toInsert)
{
  if(e < node->key_)
  {
    if(node->left_ == nullptr)
    {
      node->left_ = toInsert;
      return true;
    }
    else

      return insertNode(node->left_, e, toInsert);
  }
  else if (e > node->key_)
  {
    if(node->right_ == nullptr)
    {
      node->right_ = toInsert;
      return true;
    }
    else
      return insertNode(node->right_, e, toInsert);
  }
  return false;
}

/*
  wrapper for insertNode. Deal with root insertion case
*/
template <class K, class N> void bst<K, N>::insert(const K &e)
{

  size_++;

  if(e == key_)
    return;

  N* newNode = new N();
  newNode->key_ = e;

  // select if search will be made on left or right
  N **first = e < key_ ? &left_ : &right_;

  if (*first == nullptr)
  {
    *first = newNode;

  }
  // if the node wasn't inserted because already present free it
  else if(!insertNode(*first, e, newNode))
  {
    delete newNode;
    size_--;
  }

}

/*
  Use insertNode with a null node to detemine if the key is present
*/
template <class K, class N> bool bst<K, N>::contain(const K &e)
{
  if(e == key_)
  {
    return true ;
  }

  // select if search is made on left or right
  N* first = e < key_ ? left_ : right_;

  if( first != nullptr)
  {
    return !insertNode(first, e, nullptr);
  }
  return false;
}

/*
  left first search to delete all pointers
*/
template <class K, class N> void bst<K, N>::leftFirstDelete(N* node)
{
  if(node->left_ != nullptr)
  {
    leftFirstDelete(node->left_);
  } 
  if (node->right_ !=  nullptr)
  {
    leftFirstDelete(node->right_);   
  }
  delete node;
}

/*
  left first search to delete all pointers
*/
template <class K, class N> bst<K, N>::~bst()
{
  if(left_ != nullptr)
    leftFirstDelete(left_);
  if(right_ != nullptr)
    leftFirstDelete(right_);
  size_ = 0;
}

template<class K, class N> size_t bst<K, N>::size() const
{
  return size_;
}

#endif /* bst_hpp */