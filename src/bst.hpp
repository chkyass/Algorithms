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
  protected:
    N *root_;
    size_t size_;
    virtual bool insertNode(N*, const K&, N*);
    void leftFirstDelete(N*);

  public:
    bst(K e);
    bool contain(const K&);
    size_t size() const;
    void insert(const K&);
    virtual ~bst();
    void operator=(bst) = delete;
    bst(bst&) = delete;
};

template <class K, class N> bst<K,N>::bst(K k)
{
  size_ = 1;
  root_ = new N();
  root_->key_ = k;
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
  N* newNode = new N();
  newNode->key_ = e;

  // if the node wasn't inserted because already present free it
  if(insertNode(root_, e, newNode))
    size_++;
  else
    delete newNode;
}

/*
  Use insertNode with a null node to detemine if the key is present
*/
template <class K, class N> bool bst<K, N>::contain(const K &e)
{
  return !insertNode(root_, e, nullptr);
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
  leftFirstDelete(root_);
  size_ = 0;
}

template<class K, class N> size_t bst<K, N>::size() const
{
  return size_;
}

#endif /* bst_hpp */